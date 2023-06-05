#pragma once
#include "electricalTool.h"
class Room {
private:
	char* name;
	unsigned countOfContacts;
	double maxKw;

	ElectricalTool** electric;
	unsigned countOfElectric;

	void copyFrom(const Room& other);
	void free();
	void setName(const char* name);
	void setElectric(const ElectricalTool* const * other);
public:
	Room(const char* name, const double maxKw);
	Room(const Room& other);
	Room& operator=(const Room& other);
	~Room();

	Room& operator+=(ElectricalTool* other);
	Room& operator-=(ElectricalTool* other);
	const ElectricalTool& operator[](const char* serialNumber) const;
	ElectricalTool operator[](const char* serialNumber);

	friend Room operator+(const Room& lhs, ElectricalTool* rhs);
	friend Room operator-(const Room& lhs, ElectricalTool* rhs);

	double getAllKW() const;
	void print() const;
};
