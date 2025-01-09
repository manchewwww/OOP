#include <iostream>
#include "PairManager.h"
#include "Rational.h"
#include "IntVector.h"
#include "MyString.h"
#pragma warning(disable:4996)
int main()
{
	/* Pair
	unsigned int size;
	std::cin >> size;
	Pair* pair = new Pair[size];
	pair[0] = { 1,2 };
	pair[1] = { 3,4 };
	pair[2] = { 1,2 };
	pair[3] = { 4,5 };
	pair[4] = { 3,4 };
	PairManager p(pair,size);
	PairManager k(p.getEqPairs(), p.getSize());
	p.sortPairsArray();
	k.print();
	p.print();*/

	
	Rational rat1(1, 2);
	Rational rat2(4, 5);
	Rational rat3 = rat1 + rat2;
	rat3.print();
	rat3 *= rat2;
	rat3.print();
	rat3 /= rat2;
	rat3.print();
	std::cout << (rat1 < rat2);

	/*Vector
	int v[] = { 2,3,4,5,6 };
	IntVector first(v, 5);
	IntVector second(v, 5);
	try
	{
		std::cout << first[5];
	}
	catch (const std::exception& ab)
	{
		ab.what();
	}
	first += second;
	std::cout << std::boolalpha <<  first.empty() << " ";
	int c =first.getSize();
	std::cout << c << " ";
	first.print();*/

	/*char asd[4] = "abc";
	MyString asddd("asdfgg");
	{
		asddd.append(asd);
		asddd.pushBack('a');
		int size = strlen(asddd.getData());
		for (size_t i = 0; i < size; i++)
		{
			std::cout << asddd[i] << " ";
		}
		std::cout << std::endl;
	}
	MyString asdd("asdfgg");
	{
		asdd.append(asd);
		asdd.pushBack('a');
		std::cout << std::boolalpha << (asdd == asddd) << "\n";
	}
	MyString test = asddd + asdd;
	{
		int size1 = strlen(test.getData());
		for (size_t i = 0; i < size1; i++)
		{
			std::cout << test[i] << " ";
		}
		std::cout << std::endl;
	}*/
	MyString test1;
	std::cin >> test1;
	std::cout << test1;

	
}