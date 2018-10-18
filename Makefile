manager: main.o list.o list_node.o
	g++ -Wall -std=c++11 -o manager main.o list.o list_node.o

main.o: main.cc list.cc list_node.cc
	g++ -Wall -std=c++11 -c main.cc list.cc list_node.cc

list.o: list.cc list_node.cc
	g++ -Wall -std=c++11 -c list.cc list_node.cc

list_node.o: list_node.cc
	g++ -Wall -std=c++11 -c list_node.cc

clean:
	rm -f *.o manager
