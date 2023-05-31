#include "Periodical.h"
#include <iostream>
#pragma warning(disable:4996)

void Periodical::setPeriod(const char* period) {
    if (strcmp(period, "weekly") == 0)
        this->period = Periodicity::weekly;
    else if (strcmp(period, "monthly") == 0)
        this->period = Periodicity::monthly;
    else if (strcmp(period, "yearly") == 0)
        this->period = Periodicity::yearly;
    else
        this->period = Periodicity::unknown;
}

Periodical::Periodical() {
    period = Periodicity::unknown;
    number = 0;
}
Periodical::Periodical(const char* title, const char* period, const char* description, const unsigned number, 
                       const int libraryNumber, const unsigned year) : Base(title, description, libraryNumber, year) {
    setPeriod(period);
    this->number = number;
}
Periodical::Periodical(const char* title, const Periodicity& period, const char* description, const unsigned number, 
                       const int libraryNumber, const unsigned year) : Base(title, description, libraryNumber, year) {
    this->period = period;
    this->number = number;
}
Periodical::Periodical(const char* period, const unsigned number) {
    setPeriod(period);
    this->number = number;
}
Periodical::Periodical(const Periodicity& period, const unsigned number) {
    this->period = period;
    this->number = number;
}
Periodical::Periodical(const Periodical& other) : Base(other) {
    period = other.period;
    number = other.number;
}
Periodical& Periodical::operator=(const Periodical& other) {
    if(this != &other){
        Base::operator=(other);
        period = other.period;
        number = other.number;
    }
    return *this;
}


Periodicity Periodical::getPeriod() const {
    return period;
}
unsigned Periodical::getNumber() const {
    return number;
}
Base* Periodical::clone() const {
    return new Periodical(*this);
}
void Periodical::print() const
{
    std::cout << "Title: " << getTitle() << ", ";
    std::cout << "Description: " << getDescription() << ", ";
    std::cout << "Library number: " << getLibraryNumber() << "\n";
}

void Periodical::saveInFile(std::ostream& on) const
{
    on << "Periodical" << std::endl;
    on << (*this);
    on << (Base&)(*this);
}
char* readPeriodical(std::istream& in) {
    char buffer[1024];
    in.getline(buffer, 1024);
    char* name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
    return name;
}
std::istream& operator>>(std::istream& in, Periodical& periodical)
{
    char* temp;
    temp = readPeriodical(in);
    periodical.setPeriod(temp);
    delete[] temp;
    in >> periodical.number;
    in.ignore();
    return in;
}
std::ostream& operator<<(std::ostream& on, const Periodical& periodical)
{
    if (periodical.getPeriod() == Periodicity::weekly) {
        on << "weekly" << std::endl;
    }
    else if (periodical.getPeriod() == Periodicity::monthly) {
        on << "montly" << std::endl;
    }
    else if (periodical.getPeriod() == Periodicity::yearly) {
        on << "yearly" << std::endl;
    }
    else {
        on << "unkwown" << std::endl;
    }
    on << periodical.number << std::endl;
    return on;
}
