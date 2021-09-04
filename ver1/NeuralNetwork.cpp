#include "NeuralNetwork.hpp"

mt19937_64 mt(0);

double NeuralNetwork::learningRate = 0.05;

// Constructor
NeuralNetwork::NeuralNetwork(vector<unsigned int> &topology)
{
    this->topology = topology;

    // Random generator
    uniform_real_distribution<double> udd1(-1, 1);

    // Number of topology size
    int tSize = this->topology.size();
    // Initialize input layer
    InputLayer = Layer(this->topology[0] + 1, Neuron(topology[1]));
    for (int i = 0; i < InputLayer.size(); i++)
    {
        for (int j = 0; j < InputLayer[i].weight.size(); j++)
        {
            InputLayer[i].weight[j] = udd1(mt);
        }
    }
    // Initialize output layer
    OutputLayer = Layer(this->topology[tSize - 1], Neuron());
    // Initialize hidden layer
    HiddenLayer = Network();
    for (int i = 1; i < this->topology.size() - 1; i++)
    {
        HiddenLayer.push_back(Layer(this->topology[i] + 1, Neuron(this->topology[i + 1])));
        for (int j = 0; j < topology[i] + 1; j++)
        {
            for (int k = 0; k < topology[i + 1]; k++)
            {
                HiddenLayer[i - 1][j].weight[k] = udd1(mt);
            }
        }
    }

    // network is the body of this class.
    network.push_back(InputLayer);
    for (int i = 0; i < HiddenLayer.size(); i++)
    {
        network.push_back(HiddenLayer[i]);
    }
    network.push_back(OutputLayer);
}

// Feedforward
Vector NeuralNetwork::Feedforward(Vector &input)
{
    int layer_num = network.size();

    // 'Input' is the private variable which is for backpropagation.
    Input = input;
    // 'HiddenLayer_input' is the private variable which is for backpropagation.
    HiddenLayer_input = Matrix();
    // 'HiddenLayer_output' is the private variable which is for backpropagation.
    HiddenLayer_output = Matrix();
    // 'InputLayer_output' is the private variable which is for backpropagation.
    InputLayer_output = Vector();

    // Prepare the Vector of 'out' which is output value of this function.
    Vector out = Vector(network[layer_num - 1].size(), 0);

    // Main feedforward process.
    Vector tmp = Vector(input.size(), 0);
    Vector tmp_prev;
    for (int i = 0; i < layer_num; i++)
    {
        if (i > 0)
        {
            tmp.push_back(1); // bias
            tmp_prev = tmp;
            if (i == 1)
            {
                InputLayer_output = tmp_prev;
            }
            else
            {
                HiddenLayer_output.push_back(tmp_prev);
            }
            tmp = Vector(topology[i], 0);
        }
        if (i == 0)
        {
            // Input layer.
            for (int j = 0; j < input.size(); j++)
            {
                tmp[j] = network[i][j].ActivateFunction(input[j]);
            }
        }
        else
        {
            // Hidden and Output layer.
            Matrix weightMat = Matrix(topology[i], Vector(tmp_prev.size(), 0));
            for (int r = 0; r < weightMat.size(); r++)
            {
                for (int c = 0; c < weightMat[0].size(); c++)
                {
                    weightMat[r][c] = network[i - 1][c].weight[r];
                }
            }
            tmp = MultMatVec(weightMat, tmp_prev);
            HiddenLayer_input.push_back(tmp);
            for (int j = 0; j < tmp.size(); j++)
            {
                tmp[j] = network[i][j].ActivateFunction(tmp[j]);
            }
        }
    }

    out = tmp;
    Output = out;
    return out;
}

// Backpropagation
void NeuralNetwork::Backpropagation(Vector &train_out)
{
    int layer_num = network.size();
    Layer outputLayer = network[layer_num - 1];

    // Calculate the loss function
    double Loss = 0;
    for (int i = 0; i < outputLayer.size(); i++)
    {
        Loss += pow(Output[i] - train_out[i], 2);
    }
    cout << "Loss = " << Loss << endl;

    // Delta using backforward.
    Vector delta_output = Vector(outputLayer.size(), 0);
    for (int i = 0; i < delta_output.size(); i++)
    {
        delta_output[i] = (Output[i] - train_out[i]) * outputLayer[i].D_ActivateFunction(Output[i]);
    }
    // Backforward for output layer, and change the weight of output layer.
    for (int i = 0; i < outputLayer.size(); i++)
    {
        for (int j = 0; j < network[layer_num - 2].size(); j++)
        {
            outputLayer[i].weight[j] -= learningRate * delta_output[i] * HiddenLayer_output[HiddenLayer.size() - 1][j];
        }
    }
}