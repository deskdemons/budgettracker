#include "budgetmanager.h"

// Get values for use in pie chart
std::vector<PieChart> BudgetManager::get_graph_monthly_values() {
    std::vector<PieChart> monthly_values;
    std::vector<std::string> category_list = get_category_list();

    for (int i = 0; i < category_list.size(); i++) {
        Money money;
        double nrs_total_amt = 0;
        for (int j = 0; j < all_budget.size(); j++) {
            if (all_budget[j].get_category() == category_list[i] && all_budget[j].get_money().is_expense()) {
                nrs_total_amt += all_budget[j].get_money().get_nrs_eq_amt();
            }
        }
        Currency c;
        money.setMoney(nrs_total_amt, c, "e");
        PieChart pie_chart(category_list[i], money);
        monthly_values.push_back(pie_chart);
    }

    return monthly_values;
}

// Get values for use in bar chart
std::vector<BarGraph> BudgetManager::get_graph_yearly_values() {
    std::vector<BarGraph> yearly_values;
    // Create 12 empty b_graph objects
    for (int i = 0; i < 12; i++) {
        BarGraph b(i, 0);
        yearly_values.push_back(b);
    }

    // Finding the current year
    DateTime d;
    int current_year = d.get_year();

    // Add values to those empty objects for all budgets in list
    for (int i = 0; i < all_budget.size(); i++) {
        // We need the data values for current year only so
        if (all_budget[i].get_datettime().get_year() == current_year) {
            // Since in datetime month values ranges from 1 to 12 but the
            // Range we are using is 0 to 11
            int month_val = all_budget[i].get_datettime().get_month() - 1;

            double amount_val = all_budget[i].get_money().get_nrs_eq_amt();

            // Since we are counting total expenses only
            if (all_budget[i].get_money().is_expense()) {
                yearly_values[month_val].append_to_total(amount_val);
            }
        }
    }
    return yearly_values;
}
