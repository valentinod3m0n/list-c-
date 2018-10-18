#include <iostream>
#include "list.h"

int main(void) {
	std::cout << "Hola." << std::endl;
    List<int> list;

    list.Insert(3);
    list.Insert(2);
    list.Insert(1);
    list.Insert(5);
    list.Insert(6);
    list.Insert(-1);
    list.Insert(10);
    list.Insert(20);
    list.Insert(90);
    list.Insert(7);
    list.Insert(3);
    list.Insert(2);
    list.Insert(1);


    list.GoThrough();
}
