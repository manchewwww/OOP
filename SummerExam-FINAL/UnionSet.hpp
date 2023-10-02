#pragma once
#include "Set.hpp"

template<typename T>
class UnionSet : public Set<T> {
private:
	T* elements;
	unsigned size;
public:
	bool operator[](T element) const override;
	Set<T>* clone() const override;


	UnionSet(const Set<T>** sets, unsigned size);

	UnionSet(const UnionSet& other);
	UnionSet<T>& operator=(const UnionSet& other);
	~UnionSet();
private:
	unsigned takeSize(const Set<T>** sets, unsigned size);
	void free();
	void copyFrom(const UnionSet& other);
};
template<typename T>
inline bool UnionSet<T>::operator[](T element) const
{
	for (size_t i = 0; i < size; i++) {
		if (elements[i] == element) {
			return true;
		}
	}
	return false;
}
template<typename T>
inline Set<T>* UnionSet<T>::clone() const
{
	return new UnionSet(*this);
}
template<typename T>
inline UnionSet<T>::UnionSet(const Set<T>** sets, unsigned size) : size(takeSize(sets,size))
{
	elements = new (std::nothrow) T[this->size];
	if (elements == nullptr) {
		throw std::invalid_argument("No allocate memory");
	}
}
template<typename T>
inline UnionSet<T>::UnionSet(const UnionSet& other)
{
	copyFrom(other);
}
template<typename T>
inline UnionSet<T>& UnionSet<T>::operator=(const UnionSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
}
template<typename T>
inline UnionSet<T>::~UnionSet()
{
	free();
}
template<typename T>
inline unsigned UnionSet<T>::takeSize(const Set<T>** sets, unsigned size)
{
	return 0;
}
template<typename T>
inline void UnionSet<T>::free()
{
	delete[] elements;
}

template<typename T>
inline void UnionSet<T>::copyFrom(const UnionSet& other)
{
	size = other.size;
	elements = new (std::nothrow)T[size];
	if (elements == nullptr) {
		throw std::invalid_argument("No allocate memory");
	}
	for (size_t i = 0; i < size; i++) {
		elements[i] = other.elements[i];
	}
}
