#include "budgetmanager.h"

Money BudgetManager::get_total_for_current_user() {
    Money M;
    Currency c;

    Money expense = get_total_expense_for_current_user();
    Money income = get_total_income_for_current_user();

    if (income.get_nrs_eq_amt() >= expense.get_nrs_eq_amt()) {
        M.setMoney(income.get_nrs_eq_amt() - expense.get_nrs_eq_amt(), c, "i");
    } else {
        M.setMoney(expense.get_nrs_eq_amt() - income.get_nrs_eq_amt(), c, "e");
    }
    return M;
}

Money BudgetManager::get_total_income_for_current_user() {
    double total_amount_in_nrs = 0;
    for (int i = 0; i < all_budget.size(); i++) {
        if (all_budget[i].get_money().is_income()) {
            total_amount_in_nrs += all_budget[i].get_money().get_nrs_eq_amt();
        }
    }
    Money M;
    Currency c;
    M.setMoney(total_amount_in_nrs, c, "i");
    return M;
}

Money BudgetManager::get_total_expense_for_current_user() {
    double total_amount_in_nrs = 0;
    for (int i = 0; i < all_budget.size(); i++) {
        if (all_budget[i].get_money().is_expense()) {
            total_amount_in_nrs += all_budget[i].get_money().get_nrs_eq_amt();
        }
    }
    Money M;
    Currency c;
    M.setMoney(total_amount_in_nrs, c, "e");
    return M;
}