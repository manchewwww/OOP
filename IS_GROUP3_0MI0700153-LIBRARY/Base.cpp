#include "Base.h"
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

Base::Base() : title(nullptr), description(nullptr), libraryNumber(0), year(0) { }
Base::Base(const char* title, const char* description, const int libraryNumber, const unsigned year) {
    try
    {
        setTitle(title);
        setDescription(description);
        setLibraryNumber(libraryNumber);
        setYear(year);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (title != nullptr) {
            delete[] this->title;
        }
        if (description != nullptr) {
            delete[] this->description;
        }
    }
}
Base::Base(const Base& other) {
    copyFrom(other);
}
Base& Base::operator=(const Base& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
Base::~Base() {
    free();
}

const char* Base::getTitle() const {
    return title;
}
const char* Base::getDescription() const {
    return description;
}
unsigned Base::getLibraryNumber() const {
    return libraryNumber;
}
unsigned Base::getYear() const {
    return year;
}

void Base::copyFrom(const Base& other) {
    try
    {
        setTitle(other.title);
        setDescription(other.description);
        setLibraryNumber(other.libraryNumber);
        setYear(other.year);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (title != nullptr) {
            delete[] title;
        }
        if (description != nullptr) {
            delete[] description;
        }
    }
    
}
void Base::free() {
    delete[] title;
    delete[] description;
    title = nullptr;
    description = nullptr;
    libraryNumber = 0;
    year = 0;
}
void Base::setTitle(const char* title) {
    if (title == nullptr) {
        throw std::invalid_argument("Title must be different from nullptr");
    }
    unsigned size = strlen(title) + 1;
    this->title = new char[size];
    strcpy(this->title, title);
}
void Base::setDescription(const char* description) {
    if (description == nullptr) {
        throw std::invalid_argument("Description must be different from nullptr");
    }
    unsigned size = strlen(description) + 1;
    this->description = new char[size];
    strcpy(this->description, description);
}
void Base::setLibraryNumber(const int libraryNumber) {
    this->libraryNumber = libraryNumber;
}
void Base::setYear(const unsigned year) {
    if (year < 0) {
        throw std::invalid_argument("Invalid year");
    }
    this->year = year;
}


char* readBase(std::istream& in) {
    char buffer[1024];
    in.getline(buffer, 1024);
    char* name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
    return name;
}
std::istream& operator>>(std::istream& in, Base& base)
{
    char* temp;
    temp = readBase(in);
    base.setTitle(temp);
    delete[] temp;
    temp = readBase(in);
    base.setDescription(temp);
    delete[] temp;
    in >> base.libraryNumber;
    in >> base.year;
    in.ignore();
    return in;
}
std::ostream& operator<<(std::ostream& on, const Base& base)
{
    on << base.title << std::endl;
    on << base.description << std::endl;
    on << base.libraryNumber << std::endl;
    on << base.year << std::endl;
    return on;
}