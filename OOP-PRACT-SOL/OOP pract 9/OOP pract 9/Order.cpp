#include "Order.h"

Order::Order() 
{
	foods = new const Food * [capacity];
}
void Order::resize()
{
	capacity *= 2;
	const Food** other = new const Food * [capacity];
	for (size_t i = 0; i < size; i++) {
		other[i] = foods[i]->clone();
	}
	for (size_t i = 0; i < size; i++) {
		delete foods[i];
	}
	delete[] foods;
	foods = other;
}
void Order::copyFrom(const Order& other) {
	size = other.size;
	capacity = other.capacity;
	foods = new const Food*[capacity];
	for (size_t i = 0; i < size; i++) {
		foods[i] = other.foods[i]->clone();
	}
}
void Order::free() {
	for (size_t i = 0; i < size; i++) {
		delete foods[i];
		foods[i] = nullptr;
	}
	delete[] foods;
	size = 0;
	capacity = 0;
}

double Order::getPrice() const
{
	double price = 0;
	for (size_t i = 0; i < size; i++) {
		price += foods[i]->getPrice();
	}
	return price;
}

void Order::addFood(Food* food)
{
	if (size == capacity) {
		resize();
	}
	foods[size++] = food->clone();
}
void Order::prepare() 
{
	isPrepared = true;
}
bool Order::getPrepare() {
	return isPrepared;
}

Order::Order(const Order& other) {
	copyFrom(other);
}
Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Order::~Order()
{
	free();
}
