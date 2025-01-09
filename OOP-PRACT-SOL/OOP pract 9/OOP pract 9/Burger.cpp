#include "Burger.h"
#include <iostream>
#pragma warning(disable:4996)

Burger::Burger(const char* description, double price, unsigned patty)
   : Food("Burger", description, Type::BASICALLY, price)
{
    try
    {
        setPatty(patty);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what();
    }
}

Burger::Burger(const Burger& other) : Food(other)
{
    try
    {
        setPatty(other.patty);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what();
    }
}

Food* Burger::clone() const {
    return new Burger(*this);
}

void Burger::setPatty(unsigned patty)
{
    if (patty > 4 || patty < 0) {
        throw std::invalid_argument("Invalid number of patty.\n");
    }
    this->patty = patty;
}
const double Burger::ADDITIONAL = 2.00;

double Burger::getPrice() const
{
    if (patty == 1) {
        return price;
    }
    else {
        return (price + (patty - 1) * ADDITIONAL);
    }
}
void Burger::print() const {
    Food::print();
    std::cout << "Price: " << getPrice() << std::endl;
    std::cout << "Patty: " << patty << std::endl;
}

