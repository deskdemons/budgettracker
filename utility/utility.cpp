#include "utility.h"
#include "../networking/client/ClientConnection.h"
#include "../cclasses/budget/budgetmanager/budgetmanager.h"

bool Util_SignupMode = false;
User globalUser;

void update_global_user_with_latest_data(){
    std::cout<<"update_global_user_with_latest_data run" << std::endl;
    BudgetManager bdb(globalUser.userId);
    Money total_for_global_user = bdb.get_total_for_current_user();
    if (total_for_global_user.is_expense()){
        globalUser.balance = -1 * total_for_global_user.get_nrs_eq_amt();
    } else {
        globalUser.balance = total_for_global_user.get_nrs_eq_amt();
    }
    std::cout<<"update_global_user_with_latest_data completed with"<< globalUser.balance << std::endl;
}

bool is_backing_up = false;
bool is_restoring_data = false;

void backup_network_sa() {
    ClientConnection cc;
    BudgetManager bdb(1);
    cc.send_to_server(bdb.all_users());
}

void restore_network_sa() {
    if (!is_restoring_data) {
        is_restoring_data = true;
        ClientConnection cc;
        cc.update_with_data_from_server();
    }
}