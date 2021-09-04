OBJS = main.o Matrix.o NeuralNetwork.o Neuron.o 
CC = g++
STD = -std=c++11

all : test clean

test : $(OBJS)
	$(CC) $(STD) -o test $(OBJS)
main.o : main.cpp
	$(CC) $(STD) -c main.cpp
Matrix.o : Matrix.hpp Matrix.cpp
	$(CC) $(STD) -c Matrix.cpp
NeuralNetwork.o : NeuralNetwork.hpp NeuralNetwork.cpp
	$(CC) -c NeuralNetwork.cpp
Neuron.o : Neuron.hpp Neuron.cpp
	$(CC) -c Neuron.cpp
clean :
	rm *.o