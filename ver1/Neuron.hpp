#ifndef __Neuron__
#define __Neuron__

#include <cmath>
#include <random>
#include "Matrix.hpp"

class Neuron
{
private:
public:
    Vector weight;

    // Constructor
    Neuron();
    Neuron(int nln);

    double ActivateFunction(double x);
    double D_ActivateFunction(double x);
};

#endif