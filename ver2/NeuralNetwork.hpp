#ifndef __NeuralNetwork_hpp__
#define __NeuralNetwork_hpp__

#include "Header.hpp"

class Neuron;
class Layer;

class NeuralNetwork
{
public:
    NeuralNetwork(vector<unsigned int> &topolgy, vector<string> &names);

    vector<unsigned int> topology;

    void about();

    // Getters
    Layer *get_layer_at(int indice) { return network[indice]; };

private:
    vector<Layer *> network;
    void add_layer(Layer *l);
};

#endif