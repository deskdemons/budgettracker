#ifndef BUDGETTRACKER_BARGRAPH_H
#define BUDGETTRACKER_BARGRAPH_H

#include <vector>

class BarGraph {
    int month;
    double total;
public:
    BarGraph(int, double);

    int get_month() const;

    double get_total() const;

    void append_to_total(double);
};

#endif //BUDGETTRACKER_BARGRAPH_H
