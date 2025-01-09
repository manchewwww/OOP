#pragma once
#include "Food.h"

class Burger : public Food {
private:
	int patty;
	const static double ADDITIONAL;
public:
	Burger(const char* description, double price, unsigned patty);
	Burger(const Burger& other);
	Food* clone() const;
	void setPatty(unsigned patty);
	double getPrice() const;
	void print() const;
};