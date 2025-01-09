#include "Time.h"

Time::Time() {};
Time::Time(int hour, int min){
    setHour(hour);
    setMins(min);
}
void Time::setHour(const unsigned& hour) {
    if (hour < 0 || hour > 23) {
        throw std::invalid_argument("Invalid hour.");
    }
    this->hour = hour;
}
void Time::setMins(const unsigned& mins) {
    if (mins < 0 || mins > 59) {
        throw std::invalid_argument("Invalid minute.");
    }
    this->min = mins;
}
int Time::getHour() {
    return this->hour;
}
int Time::getMin() {
    return this->min;
}