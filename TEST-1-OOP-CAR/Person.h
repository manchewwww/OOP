#pragma once
#include <fstream>
enum Male{
	man,
	women
};
class Person {
public:
	Person();
	Person(const char* firstName, const char* secondName, const char* male, const unsigned year);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	void setFirstName(const char* firstName);
	void setSecondName(const char* secondName);
	void setMale(const char* male);
	void setYear(const unsigned year); 

	char* getFirsName() const;
	char* getSecondName() const;
	Male getMale() const;
	unsigned getYear() const;

	void writePersonInFail(std::ofstream& ofs);
	void readPersonFromFail(std::ifstream& ifs);
private: 
	char* firstName;
	char* secondName;
	Male male;
	unsigned year;

	void copy(const Person& other);
	void free();
};