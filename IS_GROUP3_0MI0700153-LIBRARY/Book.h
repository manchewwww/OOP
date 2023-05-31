#pragma once
#include "Base.h"

class Book : virtual public Base {
public:
	Book();
	Book(const char* author, const char* title, const char* publisher, const unsigned short genre,
		const char* description, const int libraryNumber, const unsigned year);
	Book(const char* author, const char* publisher, const unsigned short genre);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	const char* getAuthor() const;
	const char* getPublisher() const;
	unsigned short getGenre() const;

	Base* clone() const override;
	void print() const override;
	void saveInFile(std::ostream& on) const override;

	friend std::istream& operator>>(std::istream& in, Book& book);
	friend std::ostream& operator<<(std::ostream& on, const Book& book);

private:
	void copyFrom(const Book& other);
	void free();
	void setAuthor(const char* author);
	void setPublisher(const char* publisher);
	void setGenre(const unsigned short genre);
private:
	char* author;
	char* publisher;
	unsigned short genre;
};