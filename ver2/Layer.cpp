#include "Layer.hpp"

Layer::Layer(int indice, int num_neurons, NeuralNetwork *net)
{
    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);
    this->indice = indice;
    this->num_neurons = num_neurons;
    this->network = net;
    // Init weights
    Vector temp_weights;
    if (indice) // Input layer has no weights
    {
        for (int i = 0; i < net->topology[indice - 1]; i++)
        {
            for (int j = 0; j < num_neurons; j++)
            {
                temp_weights.push_back(dis(gen));
            }
            weights.push_back(temp_weights);
            temp_weights.clear();
        }
    }
}

void Layer::show_weights_matrix()
{
    cout << "Matrix Size : " << weights.size() << "x" << weights[0].size() << endl;
    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = 0; j < weights[i].size(); j++)
        {
            cout << " " << weights[i][j];
        }
        cout << endl;
    }
}