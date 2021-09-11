#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(vector<unsigned int> &topology, vector<string> &names)
{
    this->topology = topology;
    for (int i = 0; i < topology.size(); i++)
    {
        this->add_layer(new Layer(i, topology[i], names[i], this));
    }
}

void NeuralNetwork::sim(Vector inputs)
{
    network[0]->set_inputs(inputs);
    for (int i = 0; i < topology.size(); i++)
    {
        this->get_layer_at(i)->forward_propagate();
    }
}

void NeuralNetwork::train_by_error(Matrix inputs, Matrix targets, double target_error)
{
    double error;
    do
    {
        error = 0;
        for (int i = 0; i < inputs.size(); i++)
        {
            set_targets(targets[i]);
            sim(inputs[i]);
            for (int j = 0; j < targets[i].size(); j++)
            {
                error += pow(targets[i][j] - get_nn_outputs()[j], 2) / 2;
            }
            for (int indice = topology.size() - 1; indice >= 0; indice--)
            {
                this->get_layer_at(indice)->back_propagate();
            }
        }
        cout << "Error is " << error << endl;
    } while (error > target_error);
    cout << "Stopping at error : " << error << endl;
}

void NeuralNetwork::add_layer(Layer *l)
{
    network.push_back(l);
}

Vector NeuralNetwork::get_nn_outputs()
{
    return get_layer_at(topology.size() - 1)->get_outputs();
}

void NeuralNetwork::set_targets(Vector tar)
{
    targets = tar;
}