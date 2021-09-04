OBJS = main.o Layer.o NeuralNetwork.o Neuron.o
CC = g++
STD = -std=c++11

all : main clean

main : $(OBJS)
	$(CC) $(STD) -o main $(OBJS)
main.o : main.cpp
	$(CC) $(STD) -c main.cpp
Layer.o : Layer.cpp
	$(CC) -c Layer.cpp
NeuralNetwork.o : NeuralNetwork.cpp
	$(CC) -c NeuralNetwork.cpp
Neuron.o : Neuron.cpp
	$(CC) -c Neuron.cpp
clean : 
	rm *.o