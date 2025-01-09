#include "PairManager.h"
#include <iostream>

PairManager::PairManager(Pair* pair, unsigned size)
{
	if (&this->pairs != &pair){
		this->pairs = nullptr;
		std::swap(pair, this->pairs);
	}
	this->size = size;
}
unsigned PairManager::getSize() 
{
	unsigned newSize = 0;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (pairs[i] == pairs[j]) {
				newSize++;
			}
		}
	}
	return newSize;
}
Pair* PairManager::getEqPairs()
{
	unsigned newSize = getSize();
	Pair* newPairs = new Pair[newSize];
	int index = 0;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (pairs[i] == pairs[j]) {
				newPairs[index] = pairs[i];
				index++;
			}
		}
	}
	return newPairs;
}
void mySwap(Pair& pair1, Pair& pair2) {
	Pair temp = pair1;
	pair1 = pair2;
	pair2 = temp;
}
void PairManager::sortPairsArray()
{
	unsigned minIndex = 0;
	for (size_t i = 0; i < size; i++) {
		minIndex = i;
		for (size_t j = i + 1; j < size; j++) {
			if (pairs[j] > pairs[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			mySwap(pairs[i], pairs[minIndex]);
		}
	}
}

void PairManager::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << pairs[i] << " ";
	}
}

