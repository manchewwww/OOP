#include "Person.h"
#include <iostream>
#pragma warning(disable:4996)

void Person::copyFrom(const Person& other)
{
    try {
        setName(other.name);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
    try {
        setSecondName(other.secondName);
    }
    catch (const std::invalid_argument& e) {
        delete[] name;
        std::cout << e.what();
    }
    try {
        setThirdName(other.thirdName);
    }
    catch (const std::invalid_argument& e) {
        delete[] name;
        delete[] secondName;
        std::cout << e.what();
    }
    try {
        setEgn(other.egn);
    }
    catch (const std::invalid_argument& e) {
        delete[] name;
        delete[] secondName;
        delete[] thirdName;
        std::cout << e.what();
    }
}

void Person::free()
{
    delete[] name;
    delete[] secondName;
    delete[] thirdName;
    delete[] egn;
}

Person::Person() : name(nullptr), secondName(nullptr), thirdName(nullptr), egn(nullptr)
{
}

Person::Person(const char* name, const char* secondName, const char* thirdName, const char* egn)
{
    try {
        setName(name);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
    try {
        setSecondName(secondName);
    }
    catch (const std::invalid_argument& e) {
        delete[] this->name;
        std::cout << e.what();
    }
    try {
        setThirdName(thirdName);
    }
    catch (const std::invalid_argument& e) {
        delete[] this->name;
        delete[] this->secondName;
        std::cout << e.what();
    }
    try {
        setEgn(egn);
    }
    catch (const std::invalid_argument& e) {
        delete[] this->name;
        delete[] this->secondName;
        delete[] this->thirdName;
        std::cout << e.what();
    }
}

Person::Person(const Person& other)
{
    copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Person::~Person()
{
    free();
}

char* Person::getName()
{
    return name;
}

char* Person::getSecondName()
{
    return secondName;
}

char* Person::getThirdName()
{
    return thirdName;
}

char* Person::getEgn()
{
    return egn;
}

bool Person::operator==(const Person& other)
{
    return !strcmp(egn, other.egn);
}

bool Person::operator!=(const Person& other)
{
    return !(*this == other);
}

void Person::setName(const char* name)
{
    if ((name == nullptr || strlen(name) > 30)) {
        throw std::invalid_argument("Invalid name.");
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setSecondName(const char* secondName)
{
    if (secondName == nullptr || secondName == "\0") {
        this->secondName = nullptr;
    }
    else if (strlen(secondName) <= 30) {
        this->secondName = new char[strlen(secondName) + 1];
        strcpy(this->secondName, secondName);
    }
    else { 
        throw std::invalid_argument("Invalid second name."); 
    }
}

void Person::setThirdName(const char* thirdName)
{
    if (thirdName == nullptr || strlen(thirdName) > 30) {
        throw std::invalid_argument("Invalid third name.");
    }
    this->thirdName = new char[strlen(thirdName) + 1];
    strcpy(this->thirdName, thirdName);
}

void Person::setEgn(const char* egn)
{
    if (egn == nullptr || strlen(egn) != 10) {
        throw std::invalid_argument("Invalid egn.");
    }
    this->egn = new char[strlen(egn) + 1];
    strcpy(this->egn, egn);
}

