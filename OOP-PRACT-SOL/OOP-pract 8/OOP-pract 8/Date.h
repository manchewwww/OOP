#pragma once

class Date {
public:
	unsigned day;
	unsigned month;
	unsigned year;
public:
	Date(const unsigned day, const unsigned month, const unsigned year);
	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;
	friend bool isValidDate(const Date& date);
};
