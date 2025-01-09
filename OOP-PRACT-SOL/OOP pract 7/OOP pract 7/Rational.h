#pragma once

class Rational
{
private:
	int numerator;
	int divisor;
public:
	Rational(const int numerator, const int divisor);
	Rational(const Rational& rat);
	bool operator==(const Rational& other) const;
	bool operator!=(const Rational& other) const;
	bool operator>(const Rational& other) const;
	bool operator<(const Rational& other) const;

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);
	void print();

	friend Rational operator+(const Rational& lhs, const Rational& rhs);
	friend Rational operator-(const Rational& lhs, const Rational& rhs);
	friend Rational operator*(const Rational& lhs, const Rational& rhs);
	friend Rational operator/(const Rational& lhs, const Rational& rhs);
};
