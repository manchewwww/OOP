#pragma once
#include <iostream>
class Time {
private:
    int hour;
    int min;
public:
    Time();
    Time(int hour, int min);
    void setHour(const unsigned& hour);
    void setMins(const unsigned& mins);
    int getHour();
    int getMin();
};