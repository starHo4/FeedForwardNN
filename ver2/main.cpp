#include "Header.hpp"

vector<unsigned int> topology{2, 5, 1};
vector<string> names{"equal", "sigmoid", "equal"};

int main()
{
    NeuralNetwork *XORNet = new NeuralNetwork(topology, names);

    // test
    Layer *thisLayer = XORNet->get_layer_at(0);
    thisLayer->show_function_name();
    for (int i = 1; i < XORNet->topology.size(); i++)
    {
        thisLayer = XORNet->get_layer_at(i);
        thisLayer->show_weights_matrix();
        thisLayer->show_function_name();
    }
}