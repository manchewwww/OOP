#include "Book.h"
#include <iostream>
#pragma warning(disable:4996)
#pragma once


Book::Book() : author(nullptr), publisher(nullptr), genre(0) { }
Book::Book(const char* author, const char* title, const char* publisher, const unsigned short genre, 
           const char* description, const int libraryNumber, const unsigned year) : Base(title, description, libraryNumber, year) {
    try
    {
        setAuthor(author);
        setPublisher(publisher);
        setGenre(genre);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (author != nullptr)
            delete[] this->author;
    }
}
Book::Book(const char* author, const char* publisher, const unsigned short genre){
    try
    {
        setAuthor(author);
        setPublisher(publisher);
        setGenre(genre);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (author != nullptr)
            delete[] this->author;
    }
    
}
Book::Book(const Book& other) : Base(other) {
    copyFrom(other);
}
Book& Book::operator=(const Book& other) {
    if (this != &other) {
        Base::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}
Book::~Book() {
    free();
}

char* Book::getAuthor() const {
    return author;
}
char* Book::getPublisher() const {
    return publisher;
}
unsigned short Book::getGenre() const {
    return genre;
}
Base* Book::clone() const  {
    return new Book(*this);
}
void Book::print() const {
    std::cout << "Title: " << getTitle() << ", ";
    std::cout << "Type: " << getGenre() << ", ";
    std::cout << "Description: " << getDescription() << ", ";
    std::cout << "Library number: " << getLibraryNumber() << "\n";
}


void Book::saveInFile(std::ostream& on) const
{
    on << "Book" << std::endl;
    on << (*this);
    on << (Base&)(*this);
}
void Book::copyFrom(const Book& other) {
    try
    {
        setAuthor(other.author);
        setPublisher(other.publisher);
        setGenre(other.genre);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        if (author != nullptr)
            delete[] this->author;
    }
}
void Book::free() {
    delete[] author;
    delete[] publisher;
    author = nullptr;
    publisher = nullptr;
    genre = 0;
}
void Book::setAuthor(const char* author) {
    if (author == nullptr) {
        throw std::invalid_argument("Author must be different from nullptr");
    }
    unsigned size = strlen(author) + 1;
    this->author = new char[size];
    strcpy(this->author, author);
}
void Book::setPublisher(const char* publisher) {
    if (publisher == nullptr) {
        throw std::invalid_argument("Publisher must be different from nullptr");
    }
    unsigned size = strlen(publisher) + 1;
    this->publisher = new char[size];
    strcpy(this->publisher, publisher);
}
void Book::setGenre(const unsigned short genre) {
    this->genre = genre;
}

char* readBook(std::istream& in) {
    char buffer[1024];
    in.getline(buffer, 1024);
    char* name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
    return name;
}
std::istream& operator>>(std::istream& in, Book& book)
{
    char* temp;
    temp = readBook(in);
    book.setAuthor(temp);
    delete[] temp;
    temp = readBook(in);
    book.setPublisher(temp);
    delete[] temp;
    in >> book.genre;
    in.ignore();
    return in;
}
std::ostream& operator<<(std::ostream& on, const Book& book)
{
    on << book.author  << std::endl;
    on << book.publisher  << std::endl;
    on << book.genre  << std::endl;
    return on;
}
