#include "ABC.h"
#include <iostream>
#pragma warning(disable: 4996)

void STR::copyFrom(const STR& other)
{
	unsigned len = strlen(other.name) + 1;
	name = new char[len];
	strcpy(name, other.name);
	year = other.year;
}

void STR::free()
{
	delete[] name;
	name = nullptr;
	year = 0;
}

STR::STR() : name(nullptr), year(0)
{
}

STR::STR(const char* name, unsigned year) : year(year)
{
	unsigned size = strlen(name) + 1;
	name = new char[size];
	strcpy(this->name, name);
}

STR::STR(const STR& other)
{
	copyFrom(other);
}

STR& STR::operator=(const STR& other)
{
	if (this != &other) {
		free();
		copyFrom(other);

	}
	return *this;
}

STR::~STR()
{
	free();
}
