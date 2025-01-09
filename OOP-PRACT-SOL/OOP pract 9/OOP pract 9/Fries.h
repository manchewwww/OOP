#pragma once
#include "Food.h"

class Fries : public Food {
private:
	char* sliced;
public:
	Fries();
	Fries(const char* description, double price, const char* sliced);
	Fries(const Fries& other);
	Fries& operator=(const Fries& other);
	~Fries();
	Food* clone() const;
	double getPrice() const;
	void print() const;
private:
	void copyFrom(const Fries& other);
	void free();
};
