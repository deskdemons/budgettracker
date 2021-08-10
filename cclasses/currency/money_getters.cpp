#include "money.h"

double Money::get_nrs_eq_amt() const {
    return nrsEqAmt;
}

Currency Money::get_currency() {
    return currency;
}

bool Money::is_income() {
    if (type == "i") {
        return true;
    }
    return false;
}

bool Money::is_expense() {
    if (type == "e") {
        return true;
    }
    return false;
}