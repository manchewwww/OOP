#include "Room.h"
#include <sstream>
#pragma warning (disable:4996)

void Room::copy(const Room& other) {
	this->area = other.area;
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
}
void Room::free() {
	delete[] description;
}

Room::Room() : area(0), description(nullptr) {}

Room::Room(const double& area, const char* description) {
	setArea(area);
	setDescription(description);
}

Room::Room(const Room& other) {
	copy(other);
}

Room& Room::operator=(const Room& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Room::~Room() {
	free();
}

unsigned Room::getArea() const {
	return area;
}

char* Room::getDescription() const {
	return description;
}

void Room::setArea(const double& area) {
	if (area <= 0) {
		throw std::invalid_argument("Invalid area.");
	}
	this->area = area;
}

void Room::setDescription(const char* description) {
	if (description == nullptr) {
		throw std::invalid_argument("Invalid description");
	}
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}
