#pragma once
#include <fstream>
class MyString {
private:
	char* myString;
	int size;
	void free();
	void copy(const MyString& other);
public:
	MyString();
	MyString(const char* myString);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	void append(const char* other);
	void pushBack(const char element);
	unsigned getSize() const;
	const char* getData() const;
	bool empty();
	bool compare(const char* other);
	void erase();

	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	const char& operator[](const int n) const;
	char& operator[](const int n);
	friend std::istream& operator>>(std::istream& is, MyString& other);
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);

	
};