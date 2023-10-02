#pragma once
#include "Set.hpp"

template <typename T>
class EndSet : public Set<T> {
private:
	T* elements;
	unsigned size;
public:
	bool operator[](T element) const override;
	Set<T>* clone() const override;

	EndSet(T* elements, unsigned size);
	EndSet(const EndSet& other);
	EndSet<T>& operator=(const EndSet& other);
	~EndSet();
private:
	unsigned removeRepeats(T* elements, unsigned size) const;
	void free();
	void copyFrom(const EndSet& other);
};

template<typename T>
inline bool EndSet<T>::operator[](T element) const
{
	for (size_t i = 0; i < size; i++) {
		if (elements[i] == element) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline Set<T>* EndSet<T>::clone() const
{
	return new EndSet(*this);
}

template<typename T>
inline EndSet<T>::EndSet(T* elements, unsigned size) : size(removeRepeats(elements, size))
{
	if (elements == nullptr) {
		throw std::invalid_argument("Elements must be different from nullptr");
	}
	this->elements = new (std::nothrow) T[size];
	if (this->elements == nullptr) {
		throw std::invalid_argument("No allocate memory.");
	}
	for (size_t i = 0; i < size; i++) {
		this->elements[i] = elements[i];
	}
}

template<typename T>
inline EndSet<T>::EndSet(const EndSet& other)
{
	copyFrom(other);
}

template<typename T>
inline EndSet<T>& EndSet<T>::operator=(const EndSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline EndSet<T>::~EndSet()
{
	free();
}

template<typename T>
inline unsigned EndSet<T>::removeRepeats(T* elements, unsigned size) const
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (elements[i] == elements[j]) {
				std::swap(elements[j], elements[--size]);
			}
		}
	}
	return size;
}

template<typename T>
inline void EndSet<T>::free()
{
	delete[] elements;
}

template<typename T>
inline void EndSet<T>::copyFrom(const EndSet& other)
{
	size = other.size;
	elements = new (std::nothrow) T[size];
	if (elements == nullptr) {
		throw std::invalid_argument("No allocate memory.");
	}
	for (size_t i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}