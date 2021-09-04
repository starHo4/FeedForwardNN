#include "Header.hpp"

vector<unsigned int> topology{2, 5, 1};

int main()
{
    NeuralNetwork *XORNet = new NeuralNetwork(topology);

    // test
    for (int i = 1; i < XORNet->topology.size(); i++)
    {
        Layer *thisLayer = XORNet->get_layer_at(i);
        thisLayer->show_weights_matrix();
    }
}