#ifndef __Layer_hpp__
#define __Layer_hpp__

#include "Header.hpp"

class Layer
{
public:
    // Activate function
    

private:
    int indice;
    int num_neurons;
    Matrix weights;

    // Forwardprop
    Vector inputs;
    Vector outputs;

    // Backprop
    Vector deltas;
};

#endif