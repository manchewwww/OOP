#pragma once
#include "Set.hpp"

template <typename T, typename U>
class SetByCriteria : public Set<T> {
private:
	U func;
public:
	bool operator[](T element) const override;
	Set<T>* clone() const override;
	SetByCriteria(U func);
};

template<typename T, typename U>
inline bool SetByCriteria<T, U>::operator[](T element) const
{
	return func(element);
}

template<typename T, typename U>
inline Set<T>* SetByCriteria<T, U>::clone() const
{
	return new SetByCriteria(*this);
}

template<typename T, typename U>
inline SetByCriteria<T, U>::SetByCriteria(U func) : func(func)
{
}
