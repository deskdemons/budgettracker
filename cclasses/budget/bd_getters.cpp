# include "budget.h"

Money Budget::get_money() {
    return amount;
}

int Budget::get_user_id() const {
    return user_id;
}

std::string Budget::get_ItemName(){
    return item_name;
}

std::string Budget::get_category() {
    return category;
}

DateTime Budget::get_datettime() {
    return datetime;
}
