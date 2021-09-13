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

    void sim(Vector inputs);
    void train_by_error(Matrix inputs, Matrix targets, double target_error);

    void about();

    // Getters
    Vector get_nn_outputs();
    Layer *get_layer_at(int indice) { return network[indice]; };
    Vector get_targets() { return targets; };
    // Setters
    void set_targets(Vector tar);

private:
    vector<Layer *> network;
    Vector targets;
    void add_layer(Layer *l);
};

#endif