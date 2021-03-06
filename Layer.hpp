#ifndef __Layer_hpp__
#define __Layer_hpp__

#include "Header.hpp"

Matrix Transpose(Matrix M);
Vector MultMatVec(Matrix &M, Vector &V);

class Neuron;
class NeuralNetwork;

class Layer
{
public:
    // The body
    vector<Neuron *> thisLayer;

    // Constructor
    Layer(int indice, int num_neurons, string name, NeuralNetwork *net);

    // Main function
    void forward_propagate();
    void back_propagate();

    // Getters
    Vector get_inputs() { return inputs; };
    Vector get_outputs() { return outputs; };
    Vector get_deltas() { return deltas; };
    int get_num_neurons() { return num_neurons; };
    int get_indice() { return indice; };
    Matrix get_weights() { return weights; };

    // Setters
    void set_inputs(Vector in) { inputs = in; };
    void set_outputs(Vector out) { outputs = out; };
    void set_weights(Matrix W) { weights = W; };

    void show_weights_matrix();
    void show_function_name();
    void calc_deltas();
    void calc_new_weights();

private:
    NeuralNetwork *network;
    int indice;
    int num_neurons;
    string functionName;
    Matrix weights;

    // Forwardprop
    Vector inputs;
    Vector outputs;
    void calc_inputs();
    void calc_outputs();

    // Backprop
    Vector deltas;
};

#endif