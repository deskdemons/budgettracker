#include "../../cclasses/budget/budgetmanager/budgetmanager.h"
#include "ServerConnection.h"
#include <fstream>
#include "iostream"


ServerConnection::ServerConnection() {
    // We initialize the server to run in port 4444 and listen to it
    port = 44444;
    listener.listen(port);
    listener.accept(socket);
}

void ServerConnection::run_server() {
    // Here we store the data that is in process of being received to an array of objects which in case is chars
    // as we are communication between server and client in chars

    // An array of 100000 is used because it is a high enough value that the data that we received won't be larger
    // than 100,000. Hence, 100000 was used.
    char buffer_chars[100000];

    // The server will communicate in two ways a send mode and receive mode
    // While in mode 'r' or receive mode, it will wait for data to come, to it i.e. client -> server
    // While in mode 's' or send mode, it will send data to client i.e. server -> client
    char mode;

    // This is initialized to store the size of the data that we have received from the opposite one in the connection
    std::size_t received;

    // Here a local variable text is used to store the data that is to be sent to the client.
    std::string text;

    // By default, a server listens to a command before answering i.e. it is in receive mode, hence default mode is r
    mode = 'r';
    bool done = false;
    while (!done){
        // Codes for send mode
        if(mode == 's'){
            text = "connected";
            socket.send(text.c_str(), text.length()+1);
            mode = 'r';
        }
        // Codes for receive mode
        else if (mode == 'r'){
            socket.receive(buffer_chars, sizeof (buffer_chars), received);
            if(received > 0) {
                // G COMMAND [get]
                // This command will send the data of budgets from server, i.e. for restoring the db in client side
                if (buffer_chars[0] == 'g'){
                    // Send full csv file contents
                    text = read_full_budget_file();
                    socket.send(text.c_str(), text.length()+1);
                    // The mode will again be r after sending the data since,
                    // i.e. the server will reset back to its original configuration
                    mode = 'r';
                }

                // B COMMAND [backup]
                // Receive the stream of budget from the client to update the server database
                else if(buffer_chars[0] == 'b'){
                    // This is to send as a confirmation that the server has received the command and now whatever
                    // is sent to the server from the above client will be set in the server database
                    text="1";
                    socket.send(text.c_str(), text.length()+1);
                    std::vector<Budget> budgets_from_client;

                    // The actual stream of data that we receive from the client
                    socket.receive(buffer_chars, sizeof(buffer_chars), received);
                    if (received > 0){
                        int position;
                        std::string  full_string = buffer_chars;

                        // This is here since, we don't know how may line we are receiving
                        // hence, we are calculating such that once there are no more remaining "\n"
                        // in the continuous string we received, it is the last csv line
                        while (!done) {
                            position = full_string.find("\n");

                            if (position == -1) {
                                done = true;
                                continue;
                            }

                            std::string temp = full_string.substr(0, position);
                            Budget temp_bud(temp);
                            budgets_from_client.push_back(temp_bud);
                            full_string = full_string.substr(position + 1, full_string.size() - 1);
                        }


                        // This is for the last line, since are close the loop once no "\n" are found in the code
                        Budget temp_bud(full_string);
                        budgets_from_client.push_back(temp_bud);

                        // Update the server database with the data from the client
                        update_current_data(budgets_from_client);
                    }


                }else if (buffer_chars[0] == 'q'){
                    mode = 'q';
                    continue;
                }
                mode = 's';
            }
        }
        else if (mode == 'q'){
            done = true;
        }
    }

}

std::string ServerConnection::read_full_budget_file() {
    BudgetManager bdb(0);

    std::vector<Budget> all_user_contents =  bdb.all_users();

    std::string full_budget_text;

    for (int i =0; i<all_user_contents.size(); i++){
        full_budget_text += all_user_contents[i].serialize();

        // We are not sending \n at end of the connection
        if (i != all_user_contents.size() -1){
            full_budget_text += "\n";
        }
    }

    return full_budget_text;

}

void ServerConnection::update_current_data(std::vector<Budget> received_data) {
    // We need to make sure the file exists before trying to delete it
    file_exist_assert();
    int removed_status = std::remove("budget.csv");
    if (removed_status != 1){
        throw ("Old file could not be removed");
    }
    // write the initial line
    file_exist_assert();

    const char *fname = "budget.csv";
    std::ofstream fout(fname);

    // loop through the vector and add it to the file
    Budget empty_budget_object;
    int i;
    for (i = 0; i < received_data.size() - 1; i++) {
        fout << received_data[i].serialize(received_data[i].get_user_id()) << std::endl;
    }
    // The "fout" below doesn't have "std::endl" at end so as not to have an empty line at end of csv file
    // If empty line is present, it will create a budget object with empty values,
    // Such that when we append a line, it writes one new empty budget object every time.
    fout << received_data[i].serialize(received_data[i].get_user_id());
    fout.close();
}

void ServerConnection::file_exist_assert() {
    const char *fname = "budget.csv";

    std::fstream fs;
    fs.open(fname, std::ios::in);

    if (!fs) {
        // File doesnot exist
        //Create a file
        std::ofstream fout(fname);
        if (fout) {
            // If the creation is successful
            fout << "pk,user_id,title,category,datetime,currency";

            // Close the file handle after performing the operation
            fout.close();
        }
    }
}

int ServerConnection::get_port() const {
    return port;
}

void ServerConnection::set_port(int p) {
    port = p;
}

