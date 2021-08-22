#include "iostream"
#include "networking/client/ClientConnection.h"
#include "networking/server/ServerConnection.h"

int main(){
    try{
        char connection_type;
        std::cout << "Connection Type";
        std::cin >> connection_type;

        if(connection_type == 'c'){
            ClientConnection cc;
            char continue_char;
            bool done = false;
            std::string received_string;
            std::vector<Budget> data_from_server;
            while(!done) {
                try{
                    data_from_server = cc.get_from_server();
                }catch (std::string errorr){
                    std::cout << "TOP ERR: " << errorr << std::endl;
                }
                for (int j =0; j<data_from_server.size(); j++){
                    received_string += data_from_server[j].serialize() + "\n";
                }
                std::cout << received_string << " \n RECEIVED FROM SERVER" << std::endl;
                std::cout << "Do You want to continue" ;
                std::cin >> continue_char;
                received_string = "";
                if (continue_char == 'n')
                    done = true;
            }
        }else if (connection_type == 's'){
            ServerConnection sc;
            sc.run_server();
        }

        system("pause");

    } catch (std::string err){
        std::cout << "BOTTOM ERR: " <<err << std::endl;
    }
    return 0;
}