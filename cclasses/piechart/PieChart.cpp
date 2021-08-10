#include "PieChart.h"

PieChart::PieChart(const std::string& cat, Money money) {
    category = cat;
    amount = money;
}

std::string PieChart::get_category() {
    return category;
}

Money PieChart::get_amount() {
    return amount;
}

double PieChart::get_nrs_eq() {
    return amount.get_nrs_eq_amt();
}
