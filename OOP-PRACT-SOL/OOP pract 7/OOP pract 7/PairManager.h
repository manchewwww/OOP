#pragma once
#include "Pair.h"
class PairManager {
private:
	Pair* pairs;
	unsigned size;
public:

	PairManager(Pair* pair, unsigned size);
	unsigned getSize();
	Pair* getEqPairs();
	void sortPairsArray();
	void print() const;
};