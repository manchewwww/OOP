#pragma once


class Whiskey {
private:
	char* brand;
	unsigned years;

	void copy(const Whiskey& other);
	void free();

public:
	Whiskey();
	Whiskey(const char* brand, const unsigned years);
	Whiskey(const Whiskey& other);
	Whiskey& operator=(const Whiskey& other);
	~Whiskey();
};