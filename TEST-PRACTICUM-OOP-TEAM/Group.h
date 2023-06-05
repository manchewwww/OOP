#pragma once
#include "Person.h"

class Group {
private:
	Person* persons;
	unsigned size;
	unsigned capacity;

	void copyFrom(const Group& other);
	void free();
public:
	Group();
	Group(const Person* persons, const unsigned size);
	Group(const Group& other);
	Group& operator=(const Group& other);
	~Group();

	Group& operator+=(const Person& other);
	Group& operator-=(const Person& other);

	friend Group& operator+(const Group& lhs, const Person& rhs);
	friend Group& operator-(const Group& lhs, const Person& rhs);

	Person& operator[](const char* egn) const;
	unsigned operator()() const;
	bool operator()(const Person& other) const;

	Person* getPersons();
	unsigned getSize();

private:
	void setPersons(const Person* persons);
	void setSize(const unsigned size);
	void resize();
};