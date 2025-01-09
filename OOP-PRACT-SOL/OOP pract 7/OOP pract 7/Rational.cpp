#include "Rational.h"
#include <iostream>

Rational::Rational(const int numerator, const int divisor) : numerator(numerator), divisor(divisor)
{
}

Rational::Rational(const Rational& other)
{
	numerator = other.numerator;
	divisor = other.divisor;
}

bool Rational::operator==(const Rational& other) const
{
	if (numerator == other.numerator && divisor == other.divisor) {
		return true;
	}
	return false;
}

bool Rational::operator!=(const Rational& other) const
{
	if (numerator != other.numerator || divisor != other.divisor) {
		return true;
	}
	return false;
}

bool Rational::operator>(const Rational& other) const
{
	double ratNum = numerator / (double)divisor;
	double otherRatNum = other.numerator / (double)other.divisor;

	return ratNum > otherRatNum;
}

bool Rational::operator<(const Rational& other) const
{
	double ratNum = numerator / (double)divisor;
	double otherRatNum = other.numerator / (double)other.divisor;

	return ratNum < otherRatNum;
}

Rational& Rational::operator+=(const Rational& other)
{
	if (divisor == other.divisor) {
		numerator += other.numerator;
	}
	else {
		numerator = numerator * other.divisor + other.numerator * divisor;
		divisor = divisor * other.divisor;
	}
	return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
	if (divisor == other.divisor) {
		numerator -= other.numerator;
	}
	else {
		divisor = divisor * other.divisor;
		numerator = numerator * other.divisor - other.numerator * divisor;
	}
	return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
	numerator *= other.numerator;
	divisor *= other.divisor;
	return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
	numerator *= other.divisor;
	divisor *= other.numerator;
	return *this;
}

void Rational::print()
{
	std::cout << numerator << " ";
	std::cout << divisor << std::endl;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational newRat(lhs);
	newRat += rhs;

	return newRat;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational newRat(lhs);
	newRat -= rhs;

	return newRat;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational newRat(lhs);
	newRat *= rhs;

	return newRat;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational newRat(lhs);
	newRat /= rhs;

	return newRat;
}
