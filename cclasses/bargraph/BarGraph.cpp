#include "BarGraph.h"
#include <vector>

int BarGraph::get_month() const {
    return month;
}

double BarGraph::get_total() const {
    return total;
}

BarGraph::BarGraph(int m, double t) : total() {
    month = m;
    total = t;
}

void BarGraph::append_to_total(double val) {
    total += val;
}
