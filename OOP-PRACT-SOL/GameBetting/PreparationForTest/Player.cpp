#include "Player.h"
#include <iostream>
#pragma warning(disable: 4996)

void Player::free()
{
	delete[] name;
	delete[] password;
	name = password = nullptr;
}

void Player::copy(const Player& other)
{
	int nameSize = strlen(other.name) + 1;
	int passwordSize = strlen(other.password) + 1;
	name = new char[nameSize];
	password = new char[passwordSize];
	strcpy(name, other.name);
	strcpy(password, other.password);
	year = other.year;
	money = other.money;
}

Player::Player() : name(nullptr), password(nullptr), year(0), money(0)
{
}

Player::Player(const char* name, const char* password, unsigned year, double money)
{
	unsigned sizeName = strlen(name) + 1;
	this->name = new char[sizeName];
	strcpy(this->name, name);
	unsigned sizePassword = strlen(password) + 1;
	this->password = new char[sizePassword];
	strcpy(this->password, password);
	this->year = year;
	this->money = money;
}

Player::Player(const Player& other)
{
	copy(other);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Player::~Player()
{
	free();
}

void Player::setName(const char* name)
{
	unsigned size = strlen(name) + 1;
	char* temp = new char[size];
	strcpy(temp, name);
	delete[] name;
	name = temp;
}

