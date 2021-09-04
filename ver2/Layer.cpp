#include "Layer.hpp"

Layer::Layer(int indice, int num_neurons, string name, NeuralNetwork *net)
{
    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<double> dis(-1, 1);
    this->indice = indice;
    this->num_neurons = num_neurons;
    this->functionName = name;
    this->network = net;
    // Init activate function
    for (int i = 0; i < num_neurons; i++)
    {
        this->thisLayer.push_back(new Neuron(name));
    }
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

void Layer::show_function_name(){
    cout << "Activate function is " << this->functionName << endl;
}

void Layer::calc_inputs(){

}

void Layer::calc_outputs(){
    // 続きはここから．
}