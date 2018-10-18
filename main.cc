#include <iostream>
#include "list.h"

int main(void) {
	std::cout << "Hola." << std::endl;
    List<int> list;

    list.Insert(3);
    list.Insert(2);
    list.Insert(1);


    list.GoThrough();
}
