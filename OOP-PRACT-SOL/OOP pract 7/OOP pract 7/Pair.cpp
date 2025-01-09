#include "Pair.h"

Pair::Pair() : x(0), y(0)
{
}
Pair::Pair(const int x, const int y) : x(x), y(y)
{
}

bool Pair::operator<(const Pair& pair) const
{
	if (this->x < pair.x) {
		return false;
	}
	else if (this->y < pair.y) {
		return false;
	}
	return true;
}

bool Pair::operator>(const Pair& pair) const
{
	return (pair.x < this->x&& pair.y < this->y);
}

bool Pair::operator==(const Pair& pair) const
{
	if (this->x == pair.x && this->y == pair.y) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& ofs, const Pair& pair)
{
	ofs << '{' << pair.x << ',' << pair.y << '}' << '\0';
	return ofs;
}

std::istream& operator>>(std::istream& ifs, Pair& pair)
{
	ifs >> pair.x >> pair.y;
	return ifs;
}
