#include "iostream"
#include "../../cclasses/budget/budgetmanager/budgetmanager.h"
#include "ServerConnection.h"

ServerConnection::ServerConnection() {
    port = 44444;
    listener.listen(port);
    listener.accept(socket);
}

void ServerConnection::run_server() {
    char buffer_chars[100000];
    char mode;
    std::size_t received;

    std::string text = "connected";
    socket.send(text.c_str(),text.length()+1);

    mode = 'r';
    bool done = false;
    while (!done){
        if(mode == 's'){
            text = "connected";
            socket.send(text.c_str(), text.length()+1);
            mode = 'r';
        }
        else if (mode == 'r'){
            socket.receive(buffer_chars, sizeof (buffer_chars), received);
            if(received > 0) {
                if (buffer_chars[0] == 'g'){
                    // Send full csv file contents
                    text = read_full_budget_file();
                    socket.send(text.c_str(), text.length()+1);
                    mode = 'r';
                } else if(buffer_chars[0] == 'r'){
                    text="w";
                    socket.send(text.c_str(), text.length()+1);
                    socket.receive(buffer_chars, sizeof(buffer_chars), received);
                    if (received > 0){

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

void ServerConnection::update_current_data() {
    // Open the file in replace mode
    // write the initial line
    // separate string into different strings and save it to a vector
    // loop through the vector and add it to the file
}

