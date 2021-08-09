#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>

class DateTime {
private:
    int hour, minute, second, month, day, year;

public:
    DateTime();                                                  //when d1 object of class datetime is defined without any parameters, then current time is set
    void setDateTime();                                          //when d1.setDateTime(); , then current time is set
    bool setDateTime(int h, int m, int s, int mo, int d,
                     int y); //set time in 24 hour format as hour, minute, second, month, day, year
    bool deserialize(
            std::string datetime);                      //pass string like "12th Jan 2021 - 12:17:23 PM" and it sets private variables accordingly. String should strictly should be in aforementioned format or it returns bool as false and doesn't set any value.
    std::string getDateTime();                                   //returns a serialized datetime string
    bool operator<(DateTime obj);                                // d1<d2 returns true or false
    bool operator>(DateTime obj);

    bool operator==(DateTime obj);

    bool operator<=(DateTime const &obj);

    bool operator>=(DateTime const &obj);

    bool operator!=(DateTime const &obj);

    void addHour(int h); //adds hour and it affects days, months, and so on.
    void addMinute(int m);

    void addSecond(int s);

    void addMonth(int mo);

    void addDay(int d);

    void addYear(int y);
};

#endif
