#include "Header.hpp"

vector<unsigned int> topology{3, 5, 1};
vector<string> names{"equal", "ReLu", "equal"};

int main()
{
    NeuralNetwork *XORNet = new NeuralNetwork(topology, names);

    Matrix XOR_APP = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Matrix XOR_TAR = {{0}, {1}, {1}, {0}};

    XORNet->train_by_error(XOR_APP, XOR_TAR, 0.000001);
}