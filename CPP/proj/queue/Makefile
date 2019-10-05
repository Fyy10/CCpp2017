queue : main.cpp queue.cpp
	g++ -g -c main.cpp
	g++ -g -c queue.cpp
	g++ -g -o queue queue.o main.o

run : queue
	./queue

clean :
	rm *.o
	rm queue

debug : queue
	gdb queue
