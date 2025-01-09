#include "DonerShop.h"

void DonerShop::resize()
{
	capacity *= 2;
	Order* other = new Order[capacity];
	for (size_t i = 0; i < size; i++) {
		other[i] = orders[i];
	}
	delete[] orders;
	orders = other;

}

DonerShop::DonerShop()
{
	orders = new Order[capacity];
}

void DonerShop::createOrder(const Order& order)
{
	if (size == capacity)
		resize();
	orders[size++] = order;
}

void DonerShop::prepareOrder()
{
	for (size_t i = 0; i < size; i++) {
		if (orders[i].getPrepare() == false) {
			orders[i].prepare();
		}
	}
}

double DonerShop::getTurnover()
{
	double money = 0;
	for (size_t i = 0; i < size; i++) {
		if (orders[size].getPrepare() == true) {
			money += orders[i].getPrice();
		}
	}
	return money;
}

unsigned DonerShop::getNumberOfWaitingOrders()
{
	unsigned num = 0;
	for (size_t i = 0; i < size; i++) {
		if (orders[size].getPrepare() == false) {
			num++;
		}
	}
	return num;
}

DonerShop::~DonerShop()
{
	delete[] orders;
	orders = nullptr;
}
