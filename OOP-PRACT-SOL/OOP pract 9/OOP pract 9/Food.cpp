#include "Food.h"
#include <sstream>
#include <iostream>
#pragma warning(disable:4996)

Food::Food() : name(nullptr), description(nullptr), price(0)
{
    type = Type::UNKNOWN;
}

Food::Food(const char* name, const char* description, const Type& type, double price)
{
    unsigned nameSize = strlen(name) + 1;
    this->name = new char[nameSize];
    strcpy(this->name, name);
    unsigned descriptionSize = strlen(description) + 1;
    this->description = new char[descriptionSize];
    strcpy(this->description,description);
    this->type = type;
    this->price = price;
}

Food::Food(const Food& other)
{
    copyFrom(other);
}

Food& Food::operator=(const Food& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Food::~Food()
{
    free();
}

void Food::print() const
{
    unsigned sizeName = strlen(name);
    std::cout << "Type: ";
    for (size_t i = 0; i < sizeName; i++) {
        std::cout << name[i];
    }
    std::cout << "\nDescription: ";
    unsigned sizeDescription = strlen(description);
    for (size_t i = 0; i < sizeDescription; i++) {
        std::cout << description[i];
    }
    std::cout << "\n";
    switch (type)
    {
    case Type::BASICALLY:
        std::cout << "Type: BASICALLY\n";
        break;
    case Type::DESERT:
        std::cout << "Type: DESERT\n";
        break;
    case Type::GARNISH:
        std::cout << "Type: GARNISH\n";
        break;
    case Type::UNKNOWN:
        std::cout << "Type: UNKNOWN\n";
        break;
    default:
        break;
    }
}

void Food::copyFrom(const Food& other)
{
    unsigned nameSize = strlen(other.name) + 1;
    name = new char[nameSize];
    strcpy(name, other.name);
    unsigned descriptionSize = strlen(other.description) + 1;
    description = new char[descriptionSize];
    strcpy(description, other.description);
    type = other.type;
    price = other.price;
}

void Food::free()
{
    delete[] name;
    delete[] description;
}
