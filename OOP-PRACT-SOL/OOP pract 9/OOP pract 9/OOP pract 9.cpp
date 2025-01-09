#include <iostream>
#include "Food.h"
#include "Doner.h"
#include "Burger.h"
#include "Baklava.h"
#include "Fries.h"
#include "Order.h"
#include "DonerShop.h"

int main()
{
	Doner test("asd", 5, true, false);
	Doner test1(test);
	test1.print();
	Burger test2("asd", 7, 4);
	Burger test3(test2);
	test2.print();
	Baklava test4("asd", 123);
	Baklava test5(test4);
	test4.print();
	Fries test6("asd", 12, "ch");
	Fries test7(test6);
	test6.print();
	Order asd;
	asd.addFood(&test);
	asd.addFood(&test2);
	asd.addFood(&test6);
	
	DonerShop asdd;
	asdd.createOrder(asd);

}
