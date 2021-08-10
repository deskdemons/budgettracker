#include <iostream>
#include "datetime.h"
#include <ctime>
#include <sstream>
#include <string.h>

// using namespace std;

int dayOfMonth(int monthNum, int years) {
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (years % 4 == 0) {
        monthDay[1] = 29;
    }
    return monthDay[monthNum];
}

DateTime::DateTime() {
    time_t t = time(0);
    tm *tmp = localtime(&t);
    hour = tmp->tm_hour;
    minute = tmp->tm_min;
    second = tmp->tm_sec;
    month = tmp->tm_mon + 1;
    day = tmp->tm_mday;
    year = tmp->tm_year + 1900;
}

void DateTime::setDateTime() {
    time_t t = time(0);
    tm *tmp = localtime(&t);
    hour = tmp->tm_hour;
    minute = tmp->tm_min;
    second = tmp->tm_sec;
    month = tmp->tm_mon + 1;
    day = tmp->tm_mday;
    year = tmp->tm_year + 1900;
}

bool DateTime::setDateTime(int h, int m, int s, int mo, int d, int y) {
    if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0 || mo > 12 || mo < 0 || d < 0 || d > dayOfMonth(mo, y))
        return false;
    else {
        hour = h;
        minute = m;
        second = s;
        month = mo;
        day = d;
        year = y;
        return true;
    }
}

bool DateTime::operator<(DateTime obj) {
    if (year == obj.year) {
        if (month == obj.month) {
            if (day == obj.day) {
                if (hour == obj.hour) {
                    if (minute == obj.minute) {
                        if (second == obj.year) {
                            return false;
                        } else if (second < obj.second) {
                            return true;
                        } else {
                            return false;
                        }
                    } else if (minute < obj.minute) {
                        return true;
                    } else {
                        return false;
                    }
                } else if (hour < obj.hour) {
                    return true;
                } else {
                    return false;
                }
            } else if (day < obj.day) {
                return true;
            } else {
                return false;
            }
        } else if (month < obj.month) {
            return true;
        } else {
            return false;
        }
    } else if (year < obj.year) {
        return true;
    } else {
        return false;
    }
}

bool DateTime::operator>(DateTime obj) {
    if (year == obj.year) {
        if (month == obj.month) {
            if (day == obj.day) {
                if (hour == obj.hour) {
                    if (minute == obj.minute) {
                        if (second == obj.year) {
                            return false;
                        } else if (second > obj.second) {
                            return true;
                        } else {
                            return false;
                        }
                    } else if (minute > obj.minute) {
                        return true;
                    } else {
                        return false;
                    }
                } else if (hour > obj.hour) {
                    return true;
                } else {
                    return false;
                }
            } else if (day > obj.day) {
                return true;
            } else {
                return false;
            }
        } else if (month > obj.month) {
            return true;
        } else {
            return false;
        }
    } else if (year > obj.year) {
        return true;
    } else {
        return false;
    }
}

bool DateTime::operator==(DateTime obj) {
    if (year == obj.year && month == obj.month && day == obj.day && hour == obj.hour && minute == obj.minute &&
        second == obj.second) {
        return true;
    } else {
        return false;
    }
}

bool DateTime::operator<=(DateTime const &obj) {
    if ((*this) < obj || (*this) == obj) {
        return true;
    } else {
        return false;
    }
}

bool DateTime::operator>=(DateTime const &obj) {
    if ((*this) > obj || (*this) == obj) {
        return true;
    } else {
        return false;
    }
}

bool DateTime::operator!=(DateTime const &obj) {
    if ((*this) == obj) {
        return false;
    } else {
        return true;
    }
}

bool isNumber(std::string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

std::string intToString(int num) {
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    if (num / 10 < 1) {
        return '0' + str;
    } else {
        return str;
    }
}

int strToInt(std::string s) {
    std::stringstream st(s);
    int x = 0;
    st >> x;
    return x;
}

std::string suffixOfDay(int dy) {
    int nthDigit = dy % 10;
    if (dy == 11 || dy == 12 || dy == 13) {
        return "th";
    } else {
        if (nthDigit == 1) {
            return "st";
        } else if (nthDigit == 2) {
            return "nd";
        } else if (nthDigit == 3) {
            return "rd";
        } else {
            return "th";
        }
    }
}

std::string ampm(int hour) {
    if (hour >= 12) {
        return " PM";
    } else {
        return " AM";
    }
}

std::string monStr(int mon) {
    std::string month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return month[mon];
}

int monInt(std::string mont) {
    int numMon;
    for (int j = 0; j < 12; j++) {
        if (mont == monStr(j))
            numMon = j + 1;
    }
    return numMon;
}

void DateTime::addHour(int h) {
    int totHour = hour + h;
    if (totHour > 23) {
        hour = totHour % 24;
        addDay(totHour / 24);
    } else {
        hour = totHour;
    }
}

void DateTime::addMinute(int m) {
    int totMinute = minute + m;
    if (totMinute > 59) {
        minute = totMinute % 60;
        addHour(totMinute / 60);
    } else {
        minute = totMinute;
    }
}

void DateTime::addSecond(int s) {
    int totSecond = second + s;
    if (totSecond > 59) {
        second = totSecond % 60;
        addMinute(totSecond / 60);
    } else {
        second = totSecond;
    }
}

void DateTime::addMonth(int m) {
    int totMonth = month + m;
    if (totMonth > 12) {
        month = totMonth % 12;
        addYear(totMonth / 12);
    } else {
        month = totMonth;
    }
}

void DateTime::addDay(int d) {
    int totDay = day + d;
    if (totDay > dayOfMonth(month - 1, year)) {
        day = totDay % dayOfMonth(month - 1, year);
        addMonth(totDay / dayOfMonth(month - 1, year));
    } else {
        day = totDay;
    }
}

void DateTime::addYear(int y) {
    year = year + y;
}

std::string DateTime::getDateTime() {
    int hr;
    if (hour == 12 || hour == 0) {
        hr = 12;
    } else {
        hr = hour % 12;
    }
    return intToString(day) + suffixOfDay(day) + " " + monStr(month - 1) + " " + intToString(year) + " - " +
           intToString(hr) + ":" + intToString(minute) + ":" + intToString(second) + ampm(hour);
}

bool DateTime::deserialize(std::string datetime) {
    std::string h, m, s, mo, d, y, ap;
    if (datetime.length() != 27)
        return false;
    h = datetime.substr(16, 2);
    m = datetime.substr(19, 2);
    s = datetime.substr(22, 2);
    mo = datetime.substr(5, 3);
    d = datetime.substr(0, 2);
    y = datetime.substr(9, 4);
    ap = datetime.substr(25, 2);
    if (!isNumber(h) || !isNumber(m) || !isNumber(s) || !isNumber(d) || !isNumber(y) || isNumber(mo) || isNumber(ap))
        return false;
    if (ap != "AM" && ap != "PM")
        false;
    int c = 0;
    for (int i = 0; i < 12; i++) {
        if (mo == monStr(i))
            c++;
    }
    if (c == 0)
        return false;
    int hr, mi, se, mm, dd, yy;
    hr = strToInt(h);
    mi = strToInt(m);
    se = strToInt(s);
    mm = monInt(mo);
    dd = strToInt(d);
    yy = strToInt(y);

    if (hr > 12 || hr < 0 || mi > 59 || mi < 0 || se > 59 || se < 0 || dd < 0 || dd > dayOfMonth(mm - 1, yy))
        return false;
    if (ap == "AM") {
        if (hr == 12)
            hour = 0;
        else
            hour = hr;
    } else {
        if (hr == 12)
            hour = 12;
        else
            hour = hr + 12;
    }
    minute = mi;
    second = se;
    month = mm;
    day = dd;
    year = yy;

    return true;
}

int DateTime::get_month() {
    return month;
}

int DateTime::get_year() {
    return year;
}
