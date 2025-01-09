#include "IntVector.h"
#include <iostream>

void IntVector::copy(const IntVector& other)
{
	size = other.size;
	capacity = other.capacity;
	vector = new int[capacity];

	for (unsigned i = 0; i < size; i++) {
		vector[i] = other.vector[i];
	}
}

void IntVector::free()
{
	delete[] vector;
	vector = nullptr;
	size = 0;
	capacity = 0;
}

IntVector::IntVector() : vector(nullptr), size(0), capacity(0)
{
}

IntVector::IntVector(const unsigned capacity)
{
	this->capacity = capacity;
	this->size = 0;
	vector = new int[capacity] {0};
}

IntVector::IntVector(const int* vector, const unsigned size)
{
	this->size = size;
	this->capacity = size;
	this->vector = new int[capacity];
	for (size_t i = 0; i < this->size; i++) {
		this->vector[i] = vector[i];
	}
	/*free();
	std::swap(this->vector, vector);*/
}

IntVector::IntVector(const IntVector& other)
{
	copy(other);
}

IntVector& IntVector::operator=(const IntVector& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

IntVector::~IntVector()
{
	free();
}

void IntVector::resize()
{
	this->capacity *= 2;
	int* temp = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		temp[i] = vector[i];
	}
	delete[] vector;
	vector = temp;
}

void IntVector::add(int element)
{
	if (size == capacity) {
		resize();
	}
	vector[size++] = element;
}

unsigned IntVector::getSize()
{
	return size;
}

bool IntVector::empty()
{
	return size == 0;
}

bool IntVector::operator==(const IntVector& other)
{
	if (size != other.size) {
		return false;
	}
	for (size_t i = 0; i < size; i++) {
		if (vector[i] != other[i]) {
			return false;
		}
	}
	return true;
}

bool IntVector::operator!=(const IntVector& other)
{
	return !(vector == other.vector);
}

IntVector& IntVector::operator+=(const IntVector& other)
{
	if (size != other.size) {
		throw "Size of vector should be equal.";
	}
	for (size_t i = 0; i < size; i++) {
		vector[i] += other[i];
	}
	return *this;
}

int IntVector::operator[](unsigned n)
{
	if (n < 0 || n >= size) {
		throw "Invalid index";
	}
	return vector[n];
}

const int& IntVector::operator[](unsigned n) const
{
	if (n < 0 || n >= size) {
		throw "Invalid index";
	}
	return vector[n];
}

void IntVector::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << vector[i] << " ";
	}
}

