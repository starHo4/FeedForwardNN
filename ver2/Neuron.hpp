#ifndef __Neuron_hpp__
#define __Neuron_hpp__

#include "Header.hpp"

class Neuron
{
public:
    double ActivateFunction(double x);
    double D_ActivateFunction(double y);

    // Getters
    double getInput() {return input;};
    double getOutput() {return output;};
    string getFunctionName() { return functionName; };

    // Setters
    void setInput(double i);
    void setOutput(double o);
    void setFunctionName(string fN);

private:
    double input;
    double output;
    string functionName;
};

#endif