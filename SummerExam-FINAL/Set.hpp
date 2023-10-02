#pragma once
#include <iostream>
template <typename T>
class Set {
public:
	virtual bool operator[](T element) const = 0;
	virtual Set<T>* clone() const = 0;
	virtual ~Set() {

	};
};
