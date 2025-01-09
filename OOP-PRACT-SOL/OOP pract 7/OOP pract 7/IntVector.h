#pragma once

class IntVector
{
private:
	int* vector;
	unsigned size;
	unsigned capacity;
	void copy(const IntVector& other);
	void free();
public:
	IntVector();
	IntVector(const unsigned capacity);
	IntVector(const int* vector, const unsigned size);
	IntVector(const IntVector& other);
	IntVector& operator=(const IntVector& other);
	~IntVector();

	void resize();
	void add(int element);
	unsigned getSize();
	bool empty();

	bool operator==(const IntVector& other);
	bool operator!=(const IntVector& other);
	IntVector& operator+=(const IntVector& other);
	int operator[](unsigned n);
	const int& operator[](unsigned  n) const;
	
	void print();
};