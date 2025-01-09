#pragma once
#include "Order.h"

class DonerShop {
protected:
	Order* orders;
	unsigned size = 0;
	unsigned capacity = 8;

	void resize();
public:
	DonerShop();
	void createOrder(const Order& order);
	void prepareOrder();
	double getTurnover();	
	unsigned getNumberOfWaitingOrders();
	~DonerShop();
};
