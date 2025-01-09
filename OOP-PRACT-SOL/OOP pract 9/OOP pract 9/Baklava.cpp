#include "Baklava.h"
#pragma warning(disable:4996)

Baklava::Baklava(const char* description, double price) : Food("Baklava", description, Type::DESERT, price)
{
}

Baklava::Baklava(const Baklava& other) : Food(other)
{
}

Food* Baklava::clone() const
{
	return new Baklava(*this);
}

double Baklava::getPrice() const
{
	return price;
}

void Baklava::print() const
{
	Food::print();
	std::cout << "Price: " << getPrice() << std::endl;
}
