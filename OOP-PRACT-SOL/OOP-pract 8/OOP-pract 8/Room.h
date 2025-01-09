#pragma once

class Room {
private:
	double area;
	char* description;

	void copy(const Room& other);
	void free();
public:
	Room();
	Room(const double& area, const char* description);
	Room(const Room& other);
	Room& operator=(const Room& other);
	~Room();

	unsigned getArea() const;
	char* getDescription() const;
	void setArea(const double& area);
	void setDescription(const char* description);
};
