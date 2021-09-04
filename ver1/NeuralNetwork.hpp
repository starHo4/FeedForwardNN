#ifndef __NeuralNetwork__
#define __NeuralNetwork__

#include <vector>
#include "Neuron.hpp"

typedef vector<Neuron> Layer;
typedef vector<Layer> Network;

class NeuralNetwork
{
private:
    Layer InputLayer;
    Network HiddenLayer;
    Layer OutputLayer;

    // For backpropagation
    Vector Output;  // Final network output.
    Vector OutputLayer_input;   // Input value of output layer.
    Matrix HiddenLayer_output;  // Output value of each hidden layer.
    Matrix HiddenLayer_input;   // Input value of each hidden layer.
    Vector InputLayer_output;   // Output value of input layer.
    Vector Input;   // Input value into this network.

public:
    Network network;
    vector<unsigned int> topology;

    static double learningRate;

    // Constructor
    NeuralNetwork(vector<unsigned int> &topology);

    // Function
    Vector Feedforward(Vector &input);
    void Backpropagation(Vector &train_out);
};

#endif