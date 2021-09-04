#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(vector<unsigned int> &topology)
{
    this->topology = topology;
    for (int i = 0; i < topology.size(); i++)
    {
        this->add_layer(new Layer(i, topology[i], this));
    }
}

void NeuralNetwork::add_layer(Layer *l)
{
    network.push_back(l);
}