#pragma once
#include "Food.h"

class Doner : public Food {
private:
	bool hot;
	bool moreSauce;
	const static double ADDITIONAL;
public:
	Doner(const char* description, double price, bool hot, bool moreSauce);
	Doner(const Doner& other);
	double getPrice() const;
	Food* clone() const;
	void print() const;
};
