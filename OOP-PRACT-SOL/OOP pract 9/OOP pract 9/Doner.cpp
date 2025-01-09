#include "Doner.h"
#include "Food.h"
#include <iostream>
#pragma warning(disable:4996)

Doner::Doner(const char* description, double price, bool hot, bool moreSauce)
	: Food("Doner", description, Type::BASICALLY, price)
{
	this->hot = hot;
	this->moreSauce = moreSauce;
}

Doner::Doner(const Doner& other) : Food(other)
{
	hot = other.hot;
	moreSauce = other.moreSauce;
}

const double Doner::ADDITIONAL = 0.69;

double Doner::getPrice() const {
	if (moreSauce == true) {
		return (this->price + ADDITIONAL);
	}
	return price;
}
Food* Doner::clone() const {
	return new Doner(*this);
}


void Doner::print() const
{
	Food::print();
	std::cout << "Price: " << getPrice() << std::endl;
	std::cout << "Hot: " << std::boolalpha << hot << std::endl;
	std::cout << "More sauce: " << std::boolalpha << moreSauce << std::endl;
}
