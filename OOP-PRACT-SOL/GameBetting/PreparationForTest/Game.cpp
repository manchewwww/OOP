#include "Game.h"
#include <iostream>
#include <cmath>
#pragma warning(disable: 4996)

bool isEven(int number) {
	if (number % 2 == 0) {
		return true;
	}
	return false;
}
bool isOdd(int number) {
	if (number % 2 != 0) {
		return true;
	}
	return false;
}
bool isPrime(int number) {
	double size = sqrt(number);
	for(size_t i = 2; i < size ; i++){
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
bool isPowOfTwo(int number) {
	return !(number & (number - 1));
}
void Game::play(Player& other)
{
	if (other.year < 18) {
		throw "Year is under 18.";
	}
	while(other.money >= 0) {
		//random number
		int number;
		std::cin >> number;
		unsigned bet;
		std::cin >> bet;
		std::cin.ignore();
		char array[1024];
		std::cin.getline(array, 1024);
		if (strcmp(array, "even") == 0 && isEven(number)) {
			other.money += 1 / 5 * bet;
		}
		else if (strcmp(array, "odd") == 0 && isOdd(number)) {
			other.money += 1 / 5 * bet;
		}
		else if (strcmp(array, "prime") == 0 && isPrime(number)) {
			other.money += 1 / 2 * bet;
		}
		else if (strcmp(array, "pow of two") == 0 && isPowOfTwo(number)) {
			other.money += (10 * bet);
		}
		else {
			other.money -= bet;
		}
	}
}
