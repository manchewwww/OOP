#pragma once
#include <iostream>
#include <ctime>
#include "Base.h"

class User {
public:
	bool operator==(const User& other) const;
	bool operator!=(const User& other) const;
	bool operator<(const User& other) const;
	bool operator<=(const User& other) const;
	bool operator>(const User& other) const;
	bool operator>=(const User& other) const;

	int operator[](unsigned libraryNumber);
	const int& operator[](unsigned libraryNumber) const;
	bool operator()(const unsigned libraryNumber) const;

	User& operator+=(const Base* other);
	User& operator-=(const Base* other);
	User& operator-=(const int libraryNumberq);

	friend User operator+(const User& lhs, const Base* rhs);
	friend User operator-(const User& lhs, const Base* rhs);

	User();
	User(const char* name);
	User(const User& other);
	User& operator=(const User& other);
	~User();


	friend std::istream& operator>>(std::istream& in, User& users);
	friend std::ostream& operator<<(std::ostream& on, const User& users);

	const char* getName() const;
	const int* getReadBooks() const;
	unsigned getCountOfReadBooks() const;
	const int* getTakenBooks() const;
	unsigned getCountOfTakenBooks() const;
	const time_t* getTimeArray() const;
	
	//User(const char* name, const int* readBooks, const unsigned countOfReadBooks, const unsigned capacityOfReadBooks, const int* takenBooks, const unsigned countOfTakenBooks);
	//User& operator+=(const User& other);
	//User& operator-=(const User& other);
	//friend User operator+(const User& lhs, const User& rhs);
	//friend User operator-(const User& lhs, const User& rhs);

private:
	void copyFrom(const User& other);
	void free();
	void resize();

	void setName(const char* name);
	void setReadBooks(int libraryNumber);
	void setReadBooks(const int* readedBooks);
	void setTakenBooks(int libraryNumber);
	void setTakenBooks(const int* takenBooks);
	void setTimeArray(const time_t timeBook);
	void setTimeArray(const time_t* timeArray);
private:
	char* name;

	int* readBooks;
	unsigned countOfReadBooks;
	unsigned capacityOfReadBooks;

	int* takenBooks;
	time_t* timeArray;
	unsigned countOfTakenBooks;
	unsigned capacityOfTakenBooks;
};
