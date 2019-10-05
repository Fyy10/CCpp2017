set : main.o set.o
	g++ -g -o set main.o set.o

main.o : main.cpp
	g++ -g -c main.cpp

set.o : set.cpp
	g++ -g -c set.cpp

run : set
	./set

clean :
	rm *.o
	rm set

debug : set
	gdb set
