#pragma once

class Person {
private:
	char* name;
	char* secondName;
	char* thirdName;
	char* egn;
	
	void copyFrom(const Person& other);
	void free();
public:
	Person();
	Person(const char* name, const char* secondName, const char* thirdName, const char* egn);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	char* getName();
	char* getSecondName();
	char* getThirdName();
	char* getEgn();

	bool operator==(const Person& other);
	bool operator!=(const Person& other);
private:
	void setName(const char* name);
	void setSecondName(const char* secondName);
	void setThirdName(const char* thirdName);
	void setEgn(const char* egn);


};