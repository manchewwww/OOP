#pragma once
#include <iostream>
#include <exception>
#include <fstream>


template <typename T>
class VECTOR {
public:
	VECTOR();
	VECTOR(const T* array, unsigned count);
	VECTOR(const VECTOR& other);
	VECTOR<T>& operator=(const VECTOR& other);
	~VECTOR();
	void setArray(const T* array,unsigned size);

	unsigned getCount() const;
	T* getArray() const;
	unsigned getBytes() const;

	bool operator==(const VECTOR& other);
	bool operator!=(const VECTOR& other);
	bool operator<=(const VECTOR& other);
	bool operator>=(const VECTOR& other);
	bool operator>(const VECTOR& other);
	bool operator<(const VECTOR& other);

	T& operator[](int index) const;
	T operator[](int index);

	VECTOR<T>& operator+=(const VECTOR& other);
	VECTOR<T>& operator*=(double scalar);
	VECTOR<T>& operator-=(const VECTOR& other);
	VECTOR<T>& operator/=(double scalar);
	template<typename T>
	friend VECTOR<T> operator+(const VECTOR<T>& first, const VECTOR<T>& second);
	template<typename T>
	friend VECTOR<T> operator-(const VECTOR<T>& first, const VECTOR<T>& second);
	template<typename T>
	friend VECTOR<T> operator*(const VECTOR<T>& first, double scalar);
	template<typename T>
	friend VECTOR<T> operator/(const VECTOR<T>& first, double scalar);

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const VECTOR<T>& first);
	template<typename T>
	friend std::istream& operator>>(std::istream& is, VECTOR<T>& first);

	void print() const;
private:
	void copyFrom(const VECTOR& other);
	void free();
private:
	T* array;
	unsigned count;
	unsigned capacity;
};

template<typename T>
inline VECTOR<T>::VECTOR() : count(0), capacity(8)
{
	array = new (std::nothrow) T [capacity];
	if (array == nullptr) {
		throw std::invalid_argument("No allocate memory.");
	}
}

template<typename T>
inline VECTOR<T>::VECTOR(const T* array, unsigned count) : count(count), capacity(count * 2)
{
	this->array = new (std::nothrow) T[capacity];
	if (this->array == nullptr) {
		throw std::invalid_argument("Memory is not allocate");
	}
	for (size_t i = 0; i < count; i++) {
		this->array[i] = array[i];
	}
}

template<typename T>
inline VECTOR<T>::VECTOR(const VECTOR& other)
{
	copyFrom(other);
}

template<typename T>
inline VECTOR<T>& VECTOR<T>::operator=(const VECTOR& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline VECTOR<T>::~VECTOR()
{
	free();
}

template<typename T>
inline void VECTOR<T>::setArray(const T* array, unsigned size)
{
	capacity = size * 2;
	count = size;
	this->array = new (std::nothrow) T[capacity];
	if (this->array == nullptr) {
		throw std::invalid_argument("Memory is not allocate");
	}
	for (size_t i = 0; i < count; i++) {
		this->array[i] = array[i];
	}
}

template<typename T>
inline unsigned VECTOR<T>::getCount() const
{
	return count;
}

template<typename T>
inline T* VECTOR<T>::getArray() const
{
	return array;
}

template<typename T>
inline unsigned VECTOR<T>::getBytes() const
{
	return sizeof(T) * count;
}

template<typename T>
inline bool VECTOR<T>::operator==(const VECTOR& other)
{
	if (count != other.count) {
		return false;
	}
	for (size_t i = 0; i < count; i++) {
		if (array[i] != other.array[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool VECTOR<T>::operator!=(const VECTOR& other)
{
	return !(*this == other);
}

template<typename T>
inline bool VECTOR<T>::operator<=(const VECTOR& other)
{
	return !(*this > other);
}

template<typename T>
inline bool VECTOR<T>::operator>=(const VECTOR& other)
{
	return !(*this < other);
}

template<typename T>
inline bool VECTOR<T>::operator>(const VECTOR& other)
{
	if (count > other.count) {
		return true;
	}
	for (size_t i = 0; i < count; i++) {
		if (array[i] <= other.array[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline bool VECTOR<T>::operator<(const VECTOR& other)
{
	return ((*this != other) && (!(*this > other)));
}

template<typename T>
inline T& VECTOR<T>::operator[](int index) const
{
	if (index >= count) {
		throw std::invalid_argument("Invalid index");
	}
	return array[index];
}

template<typename T>
inline T VECTOR<T>::operator[](int index)
{
	if (index >= count) {
		throw std::invalid_argument("Invalid index");
	}
	return array[index];
}

template<typename T>
inline VECTOR<T>& VECTOR<T>::operator+=(const VECTOR& other)
{
	if (count != other.count) {
		throw std::invalid_argument("Size of two vectors must be equal.");
	}
	for (size_t i = 0; i < count; i++) {
		array[i] += other.array[i];
	}
	return *this;
}

template<typename T>
inline VECTOR<T>& VECTOR<T>::operator*=(double scalar)
{
	for (size_t i = 0; i < count; i++)
	{
		array[i] *= scalar;
	}
	return *this;
}

template<typename T>
inline VECTOR<T>& VECTOR<T>::operator-=(const VECTOR& other)
{
	if (count != other.count)
	{
		throw std::invalid_argument("Size must be equal");
	}
	for (size_t i = 0; i < count; i++)
	{
		array[i] -= other.array[i];
	}
	return *this;
}

template<typename T>
inline VECTOR<T>& VECTOR<T>::operator/=(double scalar)
{
	if (scalar == 0) {
		throw std::invalid_argument("Divisor mus be different from 0.");
	}
	for (size_t i = 0; i < count; i++)
	{
		array[i] /= scalar;
	}
	return *this;
}

template<typename T>
inline void VECTOR<T>::print() const
{
	for (size_t i = 0; i < count; i++) {
		std::cout << array[i] << " ";
	}
}

template<typename T>
inline void VECTOR<T>::copyFrom(const VECTOR& other)
{
	count = other.count;
	capacity = other.capacity;
	array = new T[capacity];
	for (size_t i = 0; i < count; i++)
	{
		array[i] = other.array[i];
	}
}

template<typename T>
inline void VECTOR<T>::free()
{
	delete array;
}
								
template <typename T>
VECTOR<T> operator+(const VECTOR<T>& first, const VECTOR<T>& second) {
	VECTOR<T> newVector(first);
	newVector += second;
	return newVector;
}
template <typename T>
VECTOR<T> operator-(const VECTOR<T>& first, const VECTOR<T>& second) {
	VECTOR<T> newVector(first);
	newVector -= second;
	return newVector;
}
template <typename T>
VECTOR<T> operator*(const VECTOR<T>& first, double scalar) {
	VECTOR<T> newVector(first);
	newVector *= scalar;
	return newVector;
}
template <typename T>
VECTOR<T> operator/(const VECTOR<T>& first, double scalar) {
	VECTOR<T> newVector(first);
	newVector /= scalar;
	return newVector;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const VECTOR<T>& first) {
	unsigned size = first.getCount();
	os << size << " ";
	for (size_t i = 0; i < size; i++) {
		os << first[i] << " ";
	}
	return os;
}
template <typename T>
std::istream& operator>>(std::istream& is, VECTOR<T>& first) {
	int count;
	is >> count;
	T* array = new T[count];
	for (size_t i = 0; i < count; i++) {
		is >> array[i];
	}
	first.setArray(array, count);
	delete array;
	return is;
}
