#include "budget.h"
#include <sstream>

std::string integer_to_string_budget(int num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

int Budget::string_to_integer(const std::string &string_value) {
    int i;
    std::istringstream ss(string_value);
    ss >> i;
    return i;
};
