#include "utility.h"
#include "../networking/client/ClientConnection.h"
#include "../cclasses/budget/budgetmanager/budgetmanager.h"

bool Util_SignupMode = false;
User globalUser;

bool is_backing_up = false;
bool is_restoring_data = false;

void backup_network_sa(){
    ClientConnection cc;
    BudgetManager bdb(1);
    cc.send_to_server(bdb.all_users());
}

void restore_network_sa(){
    if(!is_restoring_data){
        is_restoring_data = true;
        ClientConnection cc;
        cc.update_with_data_from_server();
    }
}