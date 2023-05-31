#include "User.h"
#include <iostream>
#include <ctime>
#pragma warning(disable:4996)

bool User::operator==(const User& other) const
{
    return !strcmp(name, other.name);
}
bool User::operator!=(const User& other) const
{
    return !(name == other.name);
}
bool User::operator<(const User& other) const {
    return countOfReadBooks < other.countOfReadBooks;
}
bool User::operator<=(const User& other) const {
    return !(*this > other);
}
bool User::operator>(const User& other) const {
    return countOfReadBooks > other.countOfReadBooks;
}
bool User::operator>=(const User& other) const {
    return !(*this < other);
}
int User::operator[](unsigned libraryNumber) {
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (libraryNumber == takenBooks[i]) {
            return 0;
        }
    }
    for (size_t i = 0; i < countOfReadBooks; i++) {
        if (libraryNumber == readBooks[i]) {
            return 1;
        }
    }
    return (-1);
}
const int& User::operator[](unsigned libraryNumber) const {
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (libraryNumber == readBooks[i]) {
            return 0;
        }
    }
    for (size_t i = 0; i < countOfReadBooks; i++) {
        if (libraryNumber == readBooks[i]) {
            return 1;
        }
    }
    return (-1);
}
bool User::operator()(const unsigned libraryNumber) const
{
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (takenBooks[i] == libraryNumber) {
            return ((time(0) - timeArray[i]) > 2629800);
        }
    }
    return false;
}

User& User::operator+=(const Base* other)
{
    try {
        setTakenBooks(other->getLibraryNumber());
        setTimeArray(time(0));
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return *this;
}
User& User::operator-=(const Base* other)
{
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (other->getLibraryNumber() == takenBooks[i]) {
            setReadBooks(other->getLibraryNumber());
            std::swap(takenBooks[i], takenBooks[countOfTakenBooks - 1]);
            std::swap(timeArray[i], timeArray[countOfTakenBooks - 1]);
            countOfTakenBooks--;
            return *this;
        }
    }
    throw std::invalid_argument("We dont find this book number in your taken.");
}
User& User::operator-=(const int libraryNumber)
{
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (libraryNumber == takenBooks[i]) {
            std::swap(takenBooks[i], takenBooks[countOfTakenBooks - 1]);
            std::swap(timeArray[i], timeArray[countOfTakenBooks - 1]);
            countOfTakenBooks--;
            return *this;
        }
    }
}
User operator+(const User& lhs, const Base* rhs)
{
    User temp(lhs);
    temp += rhs;
    return temp;
}
User operator-(const User& lhs, const Base* rhs)
{
    User temp(lhs);
    temp -= rhs;
    return temp;
}
std::istream& operator>>(std::istream& in, User& users)
{
    char buffer[1024];
    in.getline(buffer, 1024);
    users.name = new char[strlen(buffer) + 1];
    strcpy(users.name, buffer);
    in >> users.countOfReadBooks;
    in >> users.capacityOfReadBooks;
    users.readBooks = new int[users.capacityOfReadBooks];
    for (size_t i = 0; i < users.countOfReadBooks; i++) {
        in >> users.readBooks[i];
    }
    in >> users.countOfTakenBooks;
    users.takenBooks = new int[users.capacityOfTakenBooks];
    users.timeArray = new time_t[users.capacityOfTakenBooks];
    for (size_t i = 0; i < users.countOfTakenBooks; i++) {
        in >> users.takenBooks[i];
    }
    for (size_t i = 0; i < users.countOfTakenBooks; i++) {
        in >> users.timeArray[i];
    }
    in.ignore();
    return in;
}
std::ostream& operator<<(std::ostream& on, const User& users)
{
    on << users.name << std::endl;
    on << users.countOfReadBooks << std::endl;
    on << users.capacityOfReadBooks << std::endl;
    for (size_t i = 0; i < users.countOfReadBooks; i++) {
        if (i + 1 == users.countOfReadBooks) {
            on << users.readBooks[i] << std::endl;
            break;
        }
        on << users.readBooks[i] << " ";
    }
    on << users.countOfTakenBooks << std::endl;
    for (size_t i = 0; i < users.countOfTakenBooks; i++) {
        if (i + 1 == users.countOfTakenBooks) {
            on << users.takenBooks[i] << std::endl;
            break;
        }
        on << users.takenBooks[i] << " ";
    }
    for (size_t i = 0; i < users.countOfTakenBooks; i++) {
        if (i + 1 == users.countOfTakenBooks) {
            on << users.timeArray[i] << std::endl;
            break;
        }
        on << users.timeArray[i] << " ";
    }
    return on;
}

User::User() : name(nullptr), readBooks(nullptr), countOfReadBooks(0), capacityOfReadBooks(8), takenBooks(nullptr), timeArray(nullptr),
countOfTakenBooks(0), capacityOfTakenBooks(5)
{
}
User::User(const char* name) : countOfReadBooks(0), capacityOfReadBooks(8), countOfTakenBooks(0), capacityOfTakenBooks(5)
{
    try {
        setName(name);
        readBooks = new int[capacityOfReadBooks];
        takenBooks = new int[capacityOfTakenBooks];
        timeArray = new time_t[capacityOfTakenBooks];
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}
User::User(const User& other)
{
    copyFrom(other);
}
User& User::operator=(const User& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
User::~User()
{
    free();
}

const char* User::getName() const
{
    return name;
}
const int* User::getReadBooks() const
{
    return readBooks;
}
unsigned User::getCountOfReadBooks() const
{
    return countOfReadBooks;
}
const int* User::getTakenBooks() const
{
    return takenBooks;
}
const time_t* User::getTimeArray() const
{
    return timeArray;
}
unsigned User::getCountOfTakenBooks() const
{
    return countOfTakenBooks;
}

void User::copyFrom(const User& other)
{
    try {
        setName(other.name);
        countOfReadBooks = other.countOfReadBooks;
        capacityOfReadBooks = other.capacityOfReadBooks;
        setReadBooks(other.readBooks);
        countOfTakenBooks = other.countOfTakenBooks;
        capacityOfTakenBooks = 5;
        setTakenBooks(other.takenBooks);
        setTimeArray(other.timeArray);
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        if (name != nullptr) {
            delete[] name;
            delete[] readBooks;
        }
    }
}
void User::free()
{
    delete[] name;
    delete[] readBooks;
    delete[] takenBooks;
    delete[] timeArray;
    countOfReadBooks = 0;
    countOfTakenBooks = 0;
    name = nullptr;
    readBooks = nullptr;
    takenBooks = nullptr;
    timeArray = nullptr;
}
void User::resize()
{
    int* newReadedBooks = new int[capacityOfReadBooks *= 2];
    for (size_t i = 0; i < countOfReadBooks; i++) {
        newReadedBooks[i] = readBooks[i];
    }
    delete readBooks;
    readBooks = newReadedBooks;
}
void User::setName(const char* name) {
    if (name == nullptr)
        throw std::invalid_argument("Name must be different from nullptr.");
    unsigned size = strlen(name) + 1;
    this->name = new char[size];
    strcpy(this->name, name);
}
void User::setReadBooks(int libraryNumber)
{
    for (size_t i = 0; i < countOfReadBooks; i++) {
        if (readBooks[i] == libraryNumber) {
            return;
        }
    }
    if (countOfReadBooks == capacityOfReadBooks) {
        resize();
    }
    readBooks[countOfReadBooks++] = libraryNumber;
}
void User::setReadBooks(const int* readedBooks)
{
    this->readBooks = new int[capacityOfReadBooks];
    for (size_t i = 0; i < countOfReadBooks; i++) {
        this->readBooks[i] = readedBooks[i];
    }
}
void User::setTakenBooks(const int* takenBooks)
{
    this->takenBooks = new int[capacityOfTakenBooks];
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        this->takenBooks[i] = takenBooks[i];
    }
}
void User::setTakenBooks(int libraryNumber)
{
    if (countOfTakenBooks == capacityOfTakenBooks) {
        throw std::invalid_argument("You reached the maximum number of books.");
    }
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        if (takenBooks[i] == libraryNumber) {
            throw std::invalid_argument("You took this book.");
        }
    }
    takenBooks[countOfTakenBooks] = libraryNumber;
}
void User::setTimeArray(const time_t timeBook)
{
    timeArray[countOfTakenBooks++] = timeBook;
}
void User::setTimeArray(const time_t* timeArray)
{
    this->timeArray = new time_t[capacityOfTakenBooks];
    for (size_t i = 0; i < countOfTakenBooks; i++) {
        this->timeArray[i] = timeArray[i];
    }
}

//
//User::User(const char* name, const int* readBooks, const unsigned countOfReadBooks, const unsigned capacityOfReadBooks, const int* takenBooks,
//    const unsigned countOfTakenBooks) : countOfReadBooks(countOfReadBooks), capacityOfReadBooks(capacityOfReadBooks), countOfTakenBooks(countOfTakenBooks),
//    capacityOfTakenBooks(5)
//{
//    try {
//        setName(name);
//    }
//    catch (const std::invalid_argument& e) {
//        std::cout << e.what() << std::endl;
//    }
//    setReadBooks(readBooks);
//    try {
//        setTakenBooks(takenBooks);
//    }
//    catch (const std::invalid_argument& e) {
//        std::cout << e.what() << std::endl;
//    }
//}
//
//User& User::operator+=(const User& other) {
//    for (size_t i = 0; i < other.countOfReadBooks; i++) {
//        setReadBooks(other.readBooks[i]);
//    }
//    return *this;
//}
//
//User& User::operator-=(const User& other) {
//    return *this;
//}
//
//User operator+(const User& lhs, const User& rhs)
//{
//    User temp(lhs);
//    temp += rhs;
//    return temp;
//}
//
//User operator-(const User& lhs, const User& rhs)
//{
//    return User();
//}
