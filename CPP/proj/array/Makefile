array : main.o
	g++ -g -o array main.o

main.o : main.cpp
	g++ -g -c main.cpp

run : array
	./array

clean :
	rm *.o
	rm array

debug : array
	gdb array

