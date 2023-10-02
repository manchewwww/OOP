#pragma once
#include "Set.hpp"

template<typename T>
class SequenceSet : public Set<T> {
private:
	T* elements;
	unsigned size;
public:
	bool operator[](T element) const override;
	Set<T>* clone() const override;

	SequenceSet(const Set<T>** sets, unsigned size);

	SequenceSet(const SequenceSet& other);
	SequenceSet<T>& operator=(const SequenceSet& other);
	~SequenceSet();
private:
	unsigned takeSize(const Set<T>** sets, unsigned size);
	void free();
	void copyFrom(const SequenceSet& other);
};

template<typename T>
inline bool SequenceSet<T>::operator[](T element) const
{
	for (size_t i = 0; i < size; i++) {
		if (elements[i] == element) {
			return true;
		}
	}
	return false;
}

template<typename T>
inline Set<T>* SequenceSet<T>::clone() const
{
	return new SequenceSet(*this);
}

template<typename T>
inline SequenceSet<T>::SequenceSet(const Set<T>** sets, unsigned size) : size(takeSize(sets, size))
{
	elements = new (std::nothrow) T[this->size];
	if (elements == nullptr) {
		throw std::invalid_argument("No allocate memory");
	}

}

template<typename T>
inline SequenceSet<T>::SequenceSet(const SequenceSet& other)
{
	copyFrom(other);
}

template<typename T>
inline SequenceSet<T>& SequenceSet<T>::operator=(const SequenceSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline SequenceSet<T>::~SequenceSet()
{
	free();
}

template<typename T>
inline unsigned SequenceSet<T>::takeSize(const Set<T>** sets, unsigned size)
{
	unsigned sizeOfArr = 0;
	int index = 0;
	unsigned sizeOfSets = 0;
	for (size_t i = 0; i < size; i++) {
		if (sizeOfSets < sets[i].getSize()) {
			index = i;
			sizeOfSets = sets[i].getSize();
		}
	}
	T* elements = sets[index]->getElements();
	unsigned count = 0;
	for (size_t i = 0; i < sizeOfSets; i++) {
		if (count == size - 1) {
			sizeOfArr++;
		}
		count = 0;
		for (size_t j = 0; j < size; j++) {
			if (j != index) {
				if (sets[j]->operator[](elements[i])) {
					count++;
				}
			}
		}
	}
	return sizeOfArr;
}

template<typename T>
inline void SequenceSet<T>::free()
{
	delete[] elements;
}

template<typename T>
inline void SequenceSet<T>::copyFrom(const SequenceSet& other)
{
	size = other.size;
	elements = new(std::nothrow)T[size];
	if (elements == nullptr) {
		throw std::invalid_argument("No allocate memory");
	}
	for (size_t i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}
