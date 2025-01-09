#pragma once
#include "Food.h"
#include "Doner.h"
#include "Burger.h"
#include "Baklava.h"
#include "Fries.h"

class Order {
protected:
	const Food** foods;
	unsigned size = 0;
	unsigned capacity = 8;
	bool isPrepared = false;
	void resize();
	void copyFrom(const Order& other);
	void free();
public:
	Order();
	Order(const Order& other);
	Order& operator=(const Order& other);
	double getPrice() const;
	void addFood(Food* food);
	void prepare();
	bool getPrepare();
	~Order();
};