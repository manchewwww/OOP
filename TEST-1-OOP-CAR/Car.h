#pragma once
#include "Person.h"

class Car {
private:
	char model[128];
	Person person;
	unsigned yearOfBuying;

public:
	Car();
	Car(const char* model, const char* fname, const char* sname, const char* male, const unsigned year, const unsigned yearOfBuying);
	void setModel(const char model[128]);
	void setYear(const unsigned year);
	void setPerson(const char* fname,const  char* sName, const  char* male, const  unsigned year);
	char* getModel() const;
	Person getPerson() const;
	unsigned getYearOfBuiyng() const;
	void writeCarInFail(const char* fileName);
	void readCarFromFail(const char* fileName);
};