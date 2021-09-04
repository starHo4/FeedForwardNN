#include "Neuron.hpp"

double Neuron::ActivateFunction(double x)
{
    string name = this->functionName;
    if (name == "sigmoid")
    {
        return 1 / (1 + exp(-x));
    }
    else if (name == "tanh")
    {
        return tanh(x);
    }
    else if (name == "ReLu")
    {
        if (x < 0)
        {
            return 0;
        }
        else
        {
            return x;
        }
    }
    else
    {
        return x;
    }
}

double Neuron::D_ActivateFunction(double x)
{
    string name = this->functionName;
    if (name == "sigmoid")
    {
        return ActivateFunction(x) * (1 - ActivateFunction(x));
    }
    else if (name == "tanh")
    {
        return 1 / pow(cosh(x), 2);
    }
    else if (name == "ReLu")
    {
        if (x < 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

void Neuron::setInput(double i)
{
    this->input = i;
}

void Neuron::setOutput(double o)
{
    this->output = o;
}

void Neuron::setFunctionName(string fN)
{
    this->functionName = fN;
}