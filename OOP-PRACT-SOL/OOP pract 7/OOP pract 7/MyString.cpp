#include "MyString.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

void MyString::free()
{
    delete[] myString;
    myString = nullptr;
    size = 0;
}

void MyString::copy(const MyString& other)
{
    size = strlen(other.getData());
    myString = new char[size + 1];
    strcpy(myString, other.myString);
}

MyString::MyString() : myString(nullptr), size(0)
{
}

MyString::MyString(const char* myString)
{
    size = strlen(myString);
    this->myString = new char[size + 1];
    strcpy(this->myString, myString);
}

MyString::MyString(const MyString& other)
{
    copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copy(other);
    }
    return*this;
}

MyString::~MyString()
{
    free();
}



void MyString::append(const char* other)
{
    size += strlen(other);
    char* array = new char[size + 1];
    strcpy(array, myString);
    strcat(array, other);
    delete[] myString;
    myString = array;
}

void MyString::pushBack(const char element)
{
    size += 1;
    char* array = new char[size + 1];
    strcpy(array, myString);
    array[size - 1] = element;
    array[size] = '\0';
    delete[] myString;
    myString = array;
}

unsigned MyString::getSize() const
{
    return size;
}

const char* MyString::getData() const
{
    return myString;
}

bool MyString::empty()
{
    return size == 0;
}

bool MyString::compare(const char* other)
{
    unsigned size = strlen(myString) + 1;
    unsigned otherSize = strlen(other) + 1;
    if (size != otherSize) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        if (myString[i] != other[i]) {
            return false;
        }
    }
    return true;
}

void MyString::erase()
{
    free();
}

bool MyString::operator==(const MyString& other)
{
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        if (myString[i] != other[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& other)
{
    return !(myString == other.myString);
}

const char& MyString::operator[](const int n) const
{
    if (0 > n || strlen(myString) < n) {
        throw std::invalid_argument("Invalid index.");
    }
    return myString[n];
}

char& MyString::operator[](const int n)
{
    if (0 > n || strlen(myString) < n) {
        throw std::invalid_argument("Invalid index.");
    }
    return myString[n];
}

std::istream& operator>>(std::istream& is, MyString& other)
{
    MyString newStr("\0");
    while (true) {
        char buffer[1024];
        is.getline(buffer, 1024);
        newStr.append(buffer);
        if (is.good()) {
            break;
        }
        is.clear();
    }
    other = newStr;
    return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
    for (size_t i = 0; i < other.size; i++) {
        os << other.myString[i];
    }
    return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString other(lhs);
    other.append(rhs.getData());
    return other;
}
