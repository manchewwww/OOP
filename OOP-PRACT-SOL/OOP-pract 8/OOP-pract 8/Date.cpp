#include "Date.h"

Date::Date(const unsigned day, const unsigned month, const unsigned year) :day(day), month(month), year(year)
{
}

unsigned Date::getDay() const
{
    return day;
}

unsigned Date::getMonth() const
{
    return month;
}

unsigned Date::getYear() const
{
    return year;
}

bool isValidDate(const Date& date)
{
    unsigned day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (date.getMonth() < 0 || date.getMonth() > 12) {
        return false;
    }
    else if (date.getYear() < 0) {
        return false;
    }
    else if (date.getDay() < 0 || date.getDay() > day[date.getMonth() - 1]) {
        return false;
    }
    return true;
}
