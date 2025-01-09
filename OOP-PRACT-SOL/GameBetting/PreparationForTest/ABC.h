#pragma once
class STR {
	char* name;
	unsigned year;

	
	void copyFrom(const STR& other);
	void free();
public:
	STR();
	STR(const char* name, unsigned year);
	STR(const STR& other);
	STR& operator=(const STR& other);
	~STR();

};