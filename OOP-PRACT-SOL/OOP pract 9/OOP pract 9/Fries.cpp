#include "Fries.h"
#include <iostream>
#pragma warning(disable:4996)

Fries::Fries() : sliced(nullptr)
{
}

Fries::Fries(const char* description, double price, const char* sliced) : Food("Fries", description, Type::GARNISH, price)
{
	int size = strlen(sliced) + 1;
	this->sliced = new char[size];
	strcpy(this->sliced, sliced);
}

Fries::Fries(const Fries& other) : Food(other)
{
	copyFrom(other);
}

Fries& Fries::operator=(const Fries& other)
{
	if (this != &other) {
		Food::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Fries::~Fries()
{
	free();
}

Food* Fries::clone() const
{
	return new Fries(*this);
}

double Fries::getPrice() const
{
	return price;
}

void Fries::print() const
{
	Food::print();
	std::cout << "Price: " << getPrice() << std::endl << "Sliced: ";
	int size = strlen(sliced) + 1;
	for (size_t i = 0; i < size; i++) {
		std::cout << sliced[i];
	}
}

void Fries::copyFrom(const Fries& other)
{
	int size = strlen(other.sliced) + 1;
	sliced = new char[size];
	strcpy(sliced, other.sliced);
}

void Fries::free()
{
	delete[] sliced;
}
