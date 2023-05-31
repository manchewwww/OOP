#pragma once
#include "Base.h"
#include "Book.h"
#include "Periodical.h"
#include "Comic.h"
#include "User.h"
#include <iostream>
#pragma warning(disable:4996)

class Library {
public:
	void addPrintEdition(const Base* other, const int count);
	void removePrintEdition(const int libraryNumber);
	void print();
	void addUser(const char* name);
	void addUser(const User& other);
	void removeUser(const char* name);
	void printOverduePrintEdition() const;
	void printUsersWhichHaveTakenBookWithLibraryNumber(const int libraryNumber) const;
	void printUsers();
	void borrowingPrintEdition(const char* name, const unsigned libraryNumber);
	void returnPrintEdition(const char* name, const unsigned libraryNumber);


	Library();
	Library(const Base** library, const int* countOfBook, const unsigned sizeOfLibrary, const User* users, const unsigned sizeOfUsers);
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	const Base* const* getLibrary() const;
	const int* getCountOfBooks() const;
	unsigned getSizeOfLibrary() const;
	const User* getUsers() const;
	unsigned getSizeOfUsers() const;
private:
	void copyFrom(const Library& other);
	void free();
	void resizeLibrary();
	void resizeBooks();
	void resizeUsers();
	void sortLibrary();
	void sortUsers();

	void setLibrary(const Base* const* library);
	void setCountOfBooks(const int* countOfBooks);
	void setUsers(const User* users);
private:
	Base** library;
	int* countOfBooks;
	unsigned sizeOfLibrary;
	unsigned capacityOfLibrary;

	User* users;
	unsigned sizeOfUsers;
	unsigned capacityOfUsers;
};
