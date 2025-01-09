#include <iostream>
#include "Time.h"


int main()
{
	try
	{
		Time t();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}