#include <iostream>
#include "electricalTool.h"
#include "heatingDevice.h"
#include "Television.h"
#include "Refrigerator.h"
#include "Room.h"

int main()
{
    HeatingDevice a("brand", "model", "serialnum", 200);
    a.changeRealeased();
    a.print();
    a.changeRealeased();
    a.print();

    Television b(100, "tel", "model", "serialnum", 0.2);
    b.changeRealeased();
    b.print();

    Refrigerator c(3, "brand2", "model2", "serialnum2", 200);
    c.changeRealeased();
    c.print();
    c.changeRealeased();
    c.print();

    HeatingDevice newhear("Peshy", "Mega Heat", "P MH140-7765d", 2);
    newhear.changeRealeased();
    Room room("Bedroom", 3.0);
    room += &newhear;
    room.print();

    Room newRoom(room);
    newRoom += &b;
    newRoom.print();
    newRoom -= &newhear;
    newRoom.print();

    std::cout << newRoom.getAllKW();
}