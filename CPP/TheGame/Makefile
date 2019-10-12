TheGame.exe : acllib.o main.o human.o boy.o girl.o FFF.o
	g++ acllib.o main.o human.o boy.o girl.o FFF.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -o TheGame.exe

acllib.o : acllib.c acllib.h
	gcc -c acllib.c

main.o : main.cpp main.h
	g++ -c main.cpp

human.o : human.cpp human.h
	g++ -c human.cpp

boy.o : boy.cpp boy.h
	g++ -c boy.cpp

girl.o : girl.cpp girl.h
	g++ -c girl.cpp

FFF.o : FFF.cpp FFF.h
	g++ -c FFF.cpp

clean :
	del *.o
	del *.exe

run : TheGame.exe
	TheGame.exe
