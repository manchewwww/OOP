#include "Group.h"
#include <iostream>
#pragma warning(disable:4996)

void Group::copyFrom(const Group& other)
{
    setSize(other.size);
    setPersons(other.persons);
}

void Group::free()
{
    delete[] persons;
    persons = nullptr;
    size = 0;
}

Group::Group() : size(0), capacity(8)
{
    persons = new Person[capacity];
}

Group::Group(const Person* persons, const unsigned size) : capacity(2 * size)
{
    setSize(size);
    setPersons(persons);
}

Group::Group(const Group& other)
{
    copyFrom(other);
}

Group& Group::operator=(const Group& other)
{
    if (this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Group::~Group()
{
    free();
}

Group& Group::operator+=(const Person& other)
{
    if (size == capacity) {
        resize();
    }
    for (size_t i = 0; i < size; i++) {
        if (persons[i] == other) {
            std::cout << "We have persons with this egn. Person is not added!";
            return *this;
        }
    }
    persons[size++] = other;
    return *this;
}

Group& Group::operator-=(const Person& other)
{
    for (size_t i = 0; i < size; i++) {
        if (persons[i] == other) {
            std::swap(persons[i], persons[size - 1]);
            size--;
        }
    }
    return *this;
}

Group& operator+(const Group& lhs, const Person& rhs)
{
    Group temp(lhs);
    temp += rhs;
    return temp;
}

Group& operator-(const Group& lhs, const Person& rhs)
{
    Group temp(lhs);
    temp -= rhs;
    return temp;
}

Person& Group::operator[](const char* egn) const
{
    for (unsigned i = 0; i < size; i++) {
        if (strcmp(persons[i].getEgn(), egn) == 0) {
            return persons[i];
        }
    }
    throw std::invalid_argument("We dont have person with this egn");
}

unsigned Group::operator()() const
{
    return size;
}

bool Group::operator()(const Person& other) const
{
    for (unsigned i = 0; i < size; i++) {
        if (persons[i] == other) {
            return true;
        }
    }
    return false;
}

Person* Group::getPersons()
{
    return persons;
}

unsigned Group::getSize()
{
    return size;
}

void Group::setPersons(const Person* persons)
{
    this->persons = new Person[capacity];
    for (unsigned i = 0; i < size; i++) {
        this->persons[i] = persons[i];
    }
}

void Group::setSize(const unsigned size)
{
    this->size = size;
}

void Group::resize()
{
    Person* newPersons = new Person[capacity *= 2];
    for (unsigned i = 0; i < size; i++) {
        newPersons[i] = persons[i];
    }
    delete[] persons;
    persons = newPersons;
}

