#pragma once
#include "Set.hpp"

template <typename T>
class IntervalSet : public Set<T> {
private:
	T minBorder;
	T maxBorder;
public:
	bool operator[](T element) const override;
	Set<T>* clone() const override;

	IntervalSet(T border1, T border2);
};

template<typename T>
inline bool IntervalSet<T>::operator[](T element) const
{
	return ((element >= minBorder && element <= maxBorder) ? true : false);
}

template<typename T>
inline Set<T>* IntervalSet<T>::clone() const
{
	return new IntervalSet(*this);
}

template<typename T>
inline IntervalSet<T>::IntervalSet(T border1, T border2)
{
	if (border1 > border2) {
		minBorder = border2;
		maxBorder = border1;
	}
	else if (border1 < border2) {
		minBorder = border1;
		maxBorder = border2;
	}
	else {
		minBorder = maxBorder = border1;
	}
}
