#pragma once
#include <iostream>

template <typename T>
class Vector {
public:
	Vector() : size(0), capacity(8) {
		vector = new T[capacity];
	}
	Vector(unsigned n) : capacity(n) {
		vector = new T[capacity];
	}
	Vector(unsigned n, const T& elem) : capacity(n), size(n) {
		vector = new T[capacity];
		for (size_t i = 0; i < capacity; i++) {
			vector[i] = elem;
		}
	}
	Vector(const T* vector, const unsigned size) : size(size), capacity(size * 2) {
		this->vector = new T[capacity];
		for (size_t i = 0; i < size; i++) {
			this->vector[i] = vector[i];
		}
	}
	Vector(const Vector& other) {
		copyFrom(other);
	}
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	~Vector() {
		free();
	}

	void push_back(const T& elem) {
		if (size == capacity) {
			//resize();
		}
		vector[size++] = elem;
	}

	void pop_back() {
		size--;
	}
	
	T operator[](unsigned index) {
		if (size <= index) {
			throw std::invalid_argument("Index is bigger than size.");
		}
		return vector[index];
	}
	T& operator[](unsigned index) const {
		if (size <= index) {
			throw std::invalid_argument("Index is bigger than size.");
		}
		return vector[index];
	}

	bool empty() const {
		return this->size == 0;
	}

	unsigned lengt() const {
		return this->size;
	}

	unsigned getCapacity() const {
		return this->capacity;
	}

	void clear() {
		size = 0;
	}
private:
	void free() {
		delete[] vector;
		size = 0;
		capacity = 0;
		vector = nullptr;
	}
	void copyFrom(const Vector& other) {
		capacity = other.capacity;
		size = other.size;
		vector = new T[capacity];
		for (size_t i = 0; i < size; i++) {
			vector[i] = other.vector[i];
		}
	}
	void resize() {
		capacity *= 2;
		T* newVector = new T[capacity];
		for (size_t i = 0; i < size; i++) {
			newVector[i] = vector[i];
		}
		delete vector;
		vector = newVector;
	}
private:
	T* vector;
	unsigned size;
	unsigned capacity;
};