#pragma once

class Player {
private:
	char* name;
	char* password;
	unsigned year;
	double money;

	void free();
	void copy(const Player& other);
	friend class Game;
public:
	Player();
	Player(const char* name, const char* password, unsigned year, double money);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();
	
	void setName(const char* name);
};