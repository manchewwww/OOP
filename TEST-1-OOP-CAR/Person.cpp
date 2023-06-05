#include "Person.h"
#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

Person::Person() : firstName(nullptr), secondName(nullptr), male(man), year(0) {}

Person::Person(const char* firstName,const char* secondName, const char* male,const unsigned year)
{
    if (firstName == nullptr || secondName == nullptr) {
        return;
    }
    unsigned fSize = strlen(firstName) + 1;
    this->firstName= new char[fSize];
    strcpy(this->firstName, firstName);

    unsigned sSize = strlen(secondName) + 1;
    this->secondName = new char[sSize];
    strcpy(this->secondName, secondName);
    if (strcmp(male, "man") == 0) {
        this->male = Male::man;
    }
    else if (strcmp(male, "women") == 0) {
        this->male = Male::women;
    }
    this->year = year;
}

Person::Person(const Person& other)
{
    copy(other);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

Person::~Person()
{
    free();
}

void Person::setFirstName(const char* firstName)
{
    if (firstName[0] > 'Z' || firstName[0] < 'A') {
        throw "This is invalid name";
    }
    int size = strlen(firstName) + 1;
    for (size_t i = 1; i < size; i++) {
        if (firstName[i] > 'z' || firstName[i] < 'a') {
            throw "This is invalid name";
        }
    }
    this->firstName = new char[size];
    strcpy(this->firstName, firstName);
}

void Person::setSecondName(const char* secondName)
{
    if (secondName[0] > 'Z' || secondName[0] < 'A') {
        throw "This is invalid name";
    }
    int size = strlen(secondName) + 1;
    for (size_t i = 1; i < size; i++) {
        if (secondName[i] > 'z' || secondName[i] < 'a') {
            throw "This is invalid name";
        }
    }
    this->secondName = new char[size];
    strcpy(this->secondName, secondName);
}

void Person::setMale(const char* male)
{
    if (strcmp(male, "man") == 0) {
        this->male = Male::man;
    }
    else if (strcmp(male, "women") == 0) {
        this->male = Male::women;
    }
    else {
        throw "Male is invalid";
    }
}

void Person::setYear(const unsigned year)
{
    if (year < 0 || year > 2023) {
        throw "Invalid year.";
    }
    this->year = year;
}

char* Person::getFirsName() const
{
    return firstName;
}

char* Person::getSecondName() const
{
    return secondName;
}

Male Person::getMale() const
{
    return male;
}

unsigned Person::getYear() const
{
    return year;
}

void Person::writePersonInFail(std::ofstream& ofs) 
{
    unsigned firstSize = strlen(firstName) + 1;
    for (size_t i = 0; i < firstSize; i++) {
        ofs << firstName[i];
    }
    ofs << " ";
    if (!ofs.good()) {
        std::cout << "First name is not save corect.";
    }
    unsigned secondSize = strlen(secondName) + 1;
    for (size_t i = 0; i < firstSize; i++) {
        ofs << secondName[i];
    }
    ofs << " ";
    if (!ofs.good()) {
        std::cout << "Second name is not save corect.";
    }
    ofs << male;
    ofs << year;
    if (!ofs.good()) {
        std::cout << "File is not save corect.";
    }
}

void Person::readPersonFromFail(std::ifstream& ifs)
{
    char temp[1024];
    int index = 0;
    while (temp[index] != '\n') {
        ifs >> temp[index++];
    }
    int size = 0;
    for (size_t i = 0; temp[i] != ' '; i++) {
        size++;
    }
    firstName = new char[size];
    for (size_t i = 0; i < size; i++) {
        firstName[i] = temp[i];
    }
    firstName[size] = '\0';
    unsigned secondSize = 0;
    for (size_t i = size; temp[i] != ' '; i++) {
        secondSize++;
    }
    int indx = 0;
    secondName = new char[secondSize];
    for (size_t i = size; temp[size] != ' '; i++) {
        secondName[indx] = temp[size];
        indx++;
    }
    secondName[indx] = '\0';
    int newSize = 0;
    for (size_t i = size + secondSize; temp[i] != ' '; i++) {
        newSize++;
    }
    char* mal = new char[newSize];
    if (strcmp(mal, "man") == 0) {
        male = Male::man;
    }
    else if (strcmp(mal, "women") == 0) {
        male = Male::women;
    }
    year = temp[size + secondSize + newSize];
}

void Person::copy(const Person& other)
{
    unsigned fSize = strlen(other.firstName) + 1;
    firstName = new char[fSize];
    strcpy(firstName, other.firstName);
    unsigned sSize = strlen(other.secondName) + 1;
    secondName = new char[sSize];
    strcpy(secondName, other.secondName);
    male = other.male;
    year = other.year;
}

void Person::free()
{
    delete[] firstName;
    delete[] secondName;
    firstName = secondName = nullptr;
}
