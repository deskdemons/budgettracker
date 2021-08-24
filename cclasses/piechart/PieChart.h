#ifndef BUDGETTRACKER_PIECHART_H
#define BUDGETTRACKER_PIECHART_H

#include <string>
#include "../currency/money.h"

class PieChart {
private:
    std::string category;
    Money amount;
public:
    PieChart(const std::string &, Money);

    std::string get_category();

    Money get_amount();

    double get_nrs_eq();
};


#endif //BUDGETTRACKER_PIECHART_H
