#include "Comic.h"
#include <iostream>
#pragma warning(disable:4996)

Comic::Comic()
{
}

Comic::Comic(const char* author, const char* title, const char* publisher, const unsigned short genre, const char* period,
	const char* description, const unsigned number, const int libraryNumber, const unsigned year) :
	Book(author, publisher, genre), Periodical(period, number), Base(title, description, libraryNumber, year) {}

Comic::Comic(const Comic& other) : Base(other), Book(other), Periodical(other) { }
Base* Comic::clone() const {
	return new Comic(*this);
}

void Comic::saveInFile(std::ostream& on) const
{
	on << "Comic" << std::endl;
	on << (Book&)(*this);
	on << (Periodical&)(*this);
	on << (Base&)(*this);
}

void Comic::print() const {
	std::cout << "Title: " << getTitle() << ", ";
	std::cout << "Type: " << getGenre() << ", ";
	std::cout << "Description: " << getDescription() << ", ";
	std::cout << "Library number: " << getLibraryNumber() << "\n";
}