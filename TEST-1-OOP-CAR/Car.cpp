#include "Car.h"
#include "Person.h"
#include <iostream>
#include <fstream>


Car::Car() : model("\0"), person(nullptr, nullptr, nullptr, 0), yearOfBuying(0)
{
}

Car::Car(const char model[128], const char* fname, const char* sname, const char* male, const unsigned year, const unsigned yearOfBuying)
{
	setModel(model);
	setPerson(fname, sname, male, year);
	setYear(yearOfBuying);
}

void Car::setModel(const char model[128])
{
	if (model == nullptr) {
		throw "invalid input.";
	}
	int size = 0;
	for (size_t i = 0; model[i] != '\0'; i++)
	{
		this->model[i] = model[i];
		size = i;
	}
	this->model[size + 1] = '\0';
}

void Car::setYear(const unsigned year)
{
	if (year < 0 || year > 2023) {
		throw "Invalid input.";
	}
	this->yearOfBuying = year;
}

void Car::setPerson(const char* fname, const char* sName, const char* male, const unsigned year)
{
	Person person(fname, sName, male, year);
	this->person = person;
}

char* Car::getModel() const
{
	unsigned size = 0;
	for (size_t i = 0; model[i] != '\0'; i++)
	{
		size++;
	}
	char* temp = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = model[i];
	}
	return temp;
}

Person Car::getPerson() const
{
	return person;
}

unsigned Car::getYearOfBuiyng() const
{
	return yearOfBuying;
}

void Car::writeCarInFail(const char* fileName) {
	std::ofstream ofs(fileName);
	if (!ofs.is_open()) {
		return;
	}
	for (size_t i = 0; model[i] != '\0'; i++)
	{
		ofs << model[i];
	}
	ofs << " ";
	person.writePersonInFail(ofs);
	ofs << " " << yearOfBuying;
	if (!ofs.good()) {
		std::cout << "Data is not saved.";
	}
	ofs.close();
}
void Car::readCarFromFail(const char* fileName) {
	std::ifstream ifs(fileName);
	if (!ifs.is_open()) {
		return;
	}
	unsigned size = 0;
	char temp[1024];
	while (temp[size] != ' ') {
		ifs >> temp[size];
	}
	strcmp(model, temp);
	person.readPersonFromFail(ifs);
	ifs >> yearOfBuying;
	ifs.close();
}