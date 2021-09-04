OBJS = main.o 
CC = g++
STD = -std=c++11

all : main clean

main : $(OBJS)
	$(CC) $(STD) -o main $(OBJS)
main.o : main.cpp
	$(CC) -c main.cpp
clean : 
	rm *.o