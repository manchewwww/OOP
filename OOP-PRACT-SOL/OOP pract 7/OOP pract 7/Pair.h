#pragma once
#include <fstream>
class Pair {
private:
	int x;
	int y;
public:
	Pair();
	Pair(const int x, const int y);
	bool operator<(const Pair& pair) const;
	bool operator>(const Pair& pair) const;
	bool operator==(const Pair& pair) const;

	friend std::ostream& operator<<(std::ostream& ofs, const Pair& pair);
	friend std::istream& operator>>(std::istream& ifs, Pair& pair);


};