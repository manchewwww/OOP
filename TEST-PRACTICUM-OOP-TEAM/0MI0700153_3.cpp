#include <iostream>
#include "Person.h"
#include "Group.h"
int main()
{
    Person a("Georgi",nullptr, "Manchev", "0347174365");
    Person d("Geogi", "nullptr", "Manchv", "034717365");
    Person b("Georgi","Kostadinov", "Manchev", "0347174335");

    Person* c = new Person[2];
    c[0] = a;
    c[1] = b;
    Group abc(c, 2);
    abc += d;
    
}