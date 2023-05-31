#pragma once
#include <iostream>
#include "Book.h"
#include "Periodical.h"

class Comic : public Book, public Periodical {
public:
	Comic();
	Comic(const char* author, const char* title, const char* publisher, const unsigned short genre, const char* period, const char* description,
		  const unsigned number, const int libraryNumber, const unsigned year);
	Comic(const Comic& other);
	void print() const override;
	Base* clone() const override;
	void saveInFile(std::ostream& on) const override;
};