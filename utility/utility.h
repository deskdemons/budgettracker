#ifndef BUDGETTRACKER_UTILITY_H
#define BUDGETTRACKER_UTILITY_H

#include "../cclasses/users/user.h"

extern User globalUser;
extern bool Util_SignupMode;
extern bool is_backing_up;
extern bool is_restoring_data;
void backup_network_sa();
void restore_network_sa();

#endif //BUDGETTRACKER_UTILITY_H
