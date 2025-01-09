#pragma once
#include "Food.h"
#include <iostream>

class Baklava : public Food {
public:
	Baklava(const char* description, double price);
	Baklava(const Baklava& other);
	Food* clone() const;
	double getPrice() const;
	void print() const;
};