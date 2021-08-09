#include "budgetmanager.h"

void BudgetManager::sort_by_datetime() {
    Budget temp;
    // Sort for current user
    for (int i = 0; i < all_budget.size() - 1; i++) {
        for (int j = 0; j < all_budget.size() - i - 1; j++) {
            if (all_budget[j].get_datettime() > all_budget[j + 1].get_datettime()) {
                temp = all_budget[j];
                all_budget[j] = all_budget[j + 1];
                all_budget[j + 1] = temp;
            }
        }
    }

    // Sort for all users
    for (int i = 0; i < all_users_budget.size() - 1; i++) {
        for (int j = 0; j < all_users_budget.size() - i - 1; j++) {
            if (all_users_budget[j].get_datettime() > all_users_budget[j + 1].get_datettime()) {
                temp = all_users_budget[j];
                all_users_budget[j] = all_users_budget[j + 1];
                all_users_budget[j + 1] = temp;
            }
        }
    }
};

void BudgetManager::sort_by_amount() {
    Budget temp;
    // Sort for current user
    for (int i = 0; i < all_budget.size() - 1; i++) {
        for (int j = 0; j < all_budget.size() - i - 1; j++) {
            if (all_budget[j].get_money().get_nrs_eq_amt() > all_budget[j + 1].get_money().get_nrs_eq_amt()) {
                temp = all_budget[j];
                all_budget[j] = all_budget[j + 1];
                all_budget[j + 1] = temp;
            }
        }
    }

    // Sort for all users
    for (int i = 0; i < all_users_budget.size() - 1; i++) {
        for (int j = 0; j < all_users_budget.size() - i - 1; j++) {
            if (all_users_budget[j].get_money().get_nrs_eq_amt() >
                all_users_budget[j + 1].get_money().get_nrs_eq_amt()) {
                temp = all_users_budget[j];
                all_users_budget[j] = all_users_budget[j + 1];
                all_users_budget[j + 1] = temp;
            }
        }
    }
}