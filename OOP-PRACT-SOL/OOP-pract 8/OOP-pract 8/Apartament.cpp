#include "Apartament.h"
#include <sstream>

void Apartament::copy(const Apartament& other) {
	size = other.size;
	rooms = new Room[size];
	for (size_t i = 0; i < size; i++)
	{
		rooms[i] = other.rooms[i];
	}
}

void Apartament::free() {
	delete[] rooms;
	size = 0;
}

Apartament::Apartament() : rooms(nullptr), size(0)
{
}

Apartament::Apartament(const Room* rooms, const unsigned size) : size(size) {
	this->rooms = new Room[size];
	for (unsigned i = 0; i < size; i++) {
		this->rooms[i] = rooms[i];
	}
}

Apartament::Apartament(const Apartament& other)
{
	copy(other);
}

Apartament& Apartament::operator=(const Apartament& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Apartament::~Apartament()
{
	free();
}

double Apartament::areaOnApartament() const
{
	double areaOnApart = 0;
	for (size_t i = 0; i < size; i++) {
		areaOnApart += rooms[i].getArea();
	}
	return areaOnApart;
}

const Room& Apartament::operator[](const char* description) const
{
	for (size_t i = 0; i < size; i++) {
		if (strcmp(description, rooms[i].getDescription()) == 0) {
			return rooms[i];
		}
	}
	throw "Invalid argument.";
}

Room Apartament::operator[](const char* description)
{
	for (size_t i = 0; i < size; i++) {
		if (strcmp(description, rooms[i].getDescription()) == 0) {
			return rooms[i];
		}
	}
	throw "Invalid argument.";
}

bool Apartament::operator==(const Apartament& other)
{
	return (areaOnApartament() / size) == (other.areaOnApartament() / other.size);
}

bool Apartament::operator<=(const Apartament& other)
{
	return !(*this > other);
}

bool Apartament::operator>=(const Apartament& other)
{
	return !(*this < other);
}

bool Apartament::operator<(const Apartament& other)
{
	return (areaOnApartament() / size) < (other.areaOnApartament() / other.size);
}

bool Apartament::operator>(const Apartament& other)
{
	return (areaOnApartament() / size) > (other.areaOnApartament() / other.size);
}
