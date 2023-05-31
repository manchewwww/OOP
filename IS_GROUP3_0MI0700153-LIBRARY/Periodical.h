#pragma once
#include "Base.h"

enum class Periodicity {
	weekly,
	monthly,
	yearly,
	unknown
};

class Periodical : virtual public Base {
public:
	Periodical();
	Periodical(const char* title, const char* period, const char* description, const unsigned number, const int libraryNumber, const unsigned year);
	Periodical(const char* title, const Periodicity& period, const char* description, const unsigned number, const int libraryNumber, const unsigned year);
	Periodical(const char* period, const unsigned number);
	Periodical(const Periodicity& period, const unsigned number);
	Periodical(const Periodical& other);
	Periodical& operator=(const Periodical& other);
	Periodicity getPeriod() const;
	unsigned getNumber() const;

	Base* clone() const override;
	void print() const override;
	void saveInFile(std::ostream& on) const override;


	friend std::istream& operator>>(std::istream& in, Periodical& periodical);
	friend std::ostream& operator<<(std::ostream& on, const Periodical& periodical);

private:
	void setPeriod(const char* period);
private:
	Periodicity period;
	unsigned number;
};