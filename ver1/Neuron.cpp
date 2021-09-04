#include "Neuron.hpp"

Neuron::Neuron()
{
}

Neuron::Neuron(int next_layer_num)
{
    weight = Vector(next_layer_num, 0);
}

double Neuron::ActivateFunction(double x)
{
    return 1 / (1 + exp(-x));
}

double Neuron::D_ActivateFunction(double y)
{
    return y * (1 - y);
}