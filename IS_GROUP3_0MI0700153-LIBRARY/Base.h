#pragma once
#include <iostream>

class Base {
public:
	Base();
	Base(const char* title, const char* description,const int libraryNumber, const unsigned year);
	Base(const Base& other);
	Base& operator=(const Base& other);
	virtual ~Base();

	const char* getTitle() const;
	const char* getDescription() const;
	unsigned getLibraryNumber() const;
	unsigned getYear() const;


	virtual Base* clone() const = 0;
	virtual void print() const = 0;
	virtual void saveInFile(std::ostream& on) const = 0;

	friend std::istream& operator>>(std::istream& in, Base& base);
	friend std::ostream& operator<<(std::ostream& on, const Base& base);

private:
	void copyFrom(const Base& other);
	void free();
	void setTitle(const char* title);
	void setDescription(const char* description);
	void setLibraryNumber(const int libraryNumber);
	void setYear(const unsigned year);
private:
	char* title;
	char* description;
	int libraryNumber;
	unsigned year;
};