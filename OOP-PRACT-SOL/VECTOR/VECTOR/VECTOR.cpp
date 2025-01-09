#include <iostream>
#include <fstream>
#include "vec.hpp"

int main()
{
	int ar[4] = { 1,2,3,4 };
	int arr[4] = { 1,2,3,4 };
	try
	{
		VECTOR<int> a;
		VECTOR<int> b;
		std::cin >> a >> b;
	/*	std::cout << std::boolalpha << (a == b) << std::endl;
		std::cout << std::boolalpha << (a != b) << std::endl;
		std::cout << std::boolalpha << (a >= b) << std::endl;
		std::cout << std::boolalpha << (a <= b) << std::endl;
		std::cout << std::boolalpha << (a > b) << std::endl;
		std::cout << std::boolalpha << (a < b) << std::endl;
		a += b;
		std::cout << a << std::endl;
		b -= a;
		std::cout << b << std::endl;
		a /= 2;
		std::cout << a << std::endl;
		b *= -1;
		std::cout << b << std::endl;*/
		std::ofstream os("file.dat", std::ios::binary);
		unsigned caaa = a.getCount();
		os.write((const char*)&(caaa), sizeof(caaa));
		os.write((const char*)(a.getArray()), a.getBytes());
		os.close();
		a.~VECTOR();
		std::ifstream is("file.dat", std::ios::binary);
		unsigned c;
		is.read(reinterpret_cast<char*>(&c), sizeof(c));
		int* array = new int[c];
		is.read(reinterpret_cast<char*>(array), c * sizeof(int));
		a.setArray(array, c);
		std::cout << a << std::endl << b;
		is.close();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
}


