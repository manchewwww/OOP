#include "Room.h"
#include <iostream>
#pragma warning(disable:4996)

void Room::copyFrom(const Room& other)
{
	try
	{
		setName(other.name);
		countOfContacts = other.countOfContacts;
		maxKw = other.maxKw;
		countOfElectric = other.countOfElectric;
		setElectric(other.electric);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void Room::free()
{
	delete[] name;
	for (size_t i = 0; i < countOfElectric; i++)
	{
		delete electric[i];
	}
	delete[] electric;
}

void Room::setName(const char* name)
{
	if (name == nullptr) {
		throw std::invalid_argument("Name must be different than nullptr.");
	}
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Room::setElectric(const ElectricalTool* const * other)
{
	electric = new ElectricalTool * [countOfContacts];
	for (size_t i = 0; i < countOfElectric; i++)
	{
		electric[i] = other[i]->clone();
	}
}

Room::Room(const char* name, const double maxKw) {
	try
	{
		setName(name);
		countOfContacts = 10;
		this->maxKw = maxKw;
		electric = new ElectricalTool * [countOfContacts];
		countOfElectric = 0;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
}
Room::Room(const Room& other)
{
	copyFrom(other);
}
Room& Room::operator=(const Room& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Room::~Room()
{
	free();
}

Room& Room::operator+=(ElectricalTool* a)
{
	if (countOfContacts == countOfElectric) {
		throw std::invalid_argument("Max count of electrical tool.");
	}
	if (getAllKW() + a->getKWOnDevice() > maxKw) {
		throw std::invalid_argument("Not enough power");
	}
	electric[countOfElectric++] = a->clone();
	return *this;
	
}
Room& Room::operator-=(ElectricalTool* other)
{
	for (size_t i = 0; i < countOfElectric; i++)
	{
		if (strcmp(other->getSerialNumber(), electric[i]->getSerialNumber()) == 0) {
			std::swap(electric[i], electric[countOfElectric - 1]);
			countOfElectric -= 1;
		}
	}
	return *this;
}

const ElectricalTool& Room::operator[](const char* serialNumber) const
{
	for (size_t i = 0; i < countOfElectric; i++)
	{
		if (strcmp(serialNumber, electric[i]->getSerialNumber()) == 0) {
			return *electric[i];
		}
	}
	throw std::invalid_argument("dont have this ser num");
}


double Room::getAllKW() const
{
	double kw = 0;
	for (size_t i = 0; i < countOfElectric; i++) {
		kw += electric[i]->getKWOnDevice();
	}
	return kw;
}

void Room::print() const
{
	std::cout << name << std::endl;
	std::cout << maxKw << std::endl;
	for (size_t i = 0; i < countOfElectric; i++)
	{
		electric[i]->print();
	}
}


Room operator+(const Room& lhs, ElectricalTool* rhs)
{
	Room newRoom(lhs);
	newRoom += rhs;
	return newRoom;
}

Room operator-(const Room& lhs,ElectricalTool* rhs)
{
	Room newRoom(lhs);
	newRoom -= rhs;
	return newRoom;
}
