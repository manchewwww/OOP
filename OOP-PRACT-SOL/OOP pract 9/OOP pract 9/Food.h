#pragma once

enum class Type {
	BASICALLY,
	DESERT,
	GARNISH,
	UNKNOWN
};
class Food {
protected:
	char* name;
	char* description;
	Type type;
	double price;
public:
	Food();
	Food(const char* name, const char* description, const Type& type, double price);
	Food(const Food& other);
	Food& operator=(const Food& other);
	virtual ~Food();
	virtual double getPrice() const = 0;
	virtual Food* clone() const = 0;
	void print() const;
private:
	void copyFrom(const Food& other);
	void free();
};
