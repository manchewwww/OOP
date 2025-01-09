#pragma once
#include "Room.h"

class Apartament {
private:
	Room* rooms;
	unsigned size;
	
	void copy(const Apartament& other);
	void free();
public:
	Apartament();
	Apartament(const Room* rooms, const unsigned size);
	Apartament(const Apartament& other);
	Apartament& operator=(const Apartament& other);
	~Apartament();

	double areaOnApartament() const;
	const Room& operator[](const char* description) const;
	Room operator[](const char* description);
	bool operator==(const Apartament& other);
	bool operator<=(const Apartament& other);
	bool operator>=(const Apartament& other);
	bool operator<(const Apartament& other);
	bool operator>(const Apartament& other);
};