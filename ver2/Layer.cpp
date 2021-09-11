#include "Layer.hpp"

// Transpose Matrix
Matrix Transpose(Matrix M)
{
    Matrix out(M[0].size(), Vector(M.size(), 0));
    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[0].size(); j++)
        {
            out[i][j] = M[j][i];
        }
    }
    return out;
}

// Multiplication of matrix and col vector.
Vector MultMatVec(Matrix &M, Vector &V)
{
    if (M[0].size() != V.size())
    {
        cout << "error" << endl;
        exit(0);
    }
    Vector out(M.size(), 0);
    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < V.size(); j++)
        {
            out[i] += M[i][j] * V[j];
        }
    }
    return out;
}

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
        for (int i = 0; i < num_neurons; i++)
        {
            for (int j = 0; j < net->topology[indice - 1]; j++)
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

void Layer::show_function_name()
{
    cout << "Activate function is " << this->functionName << endl;
}

void Layer::calc_inputs()
{
    if (indice > 0)
    {
        Vector prev_outputs = network->get_layer_at(indice - 1)->get_outputs();
        inputs = MultMatVec(weights, prev_outputs);
    }
}

void Layer::calc_outputs()
{
    outputs = Vector(num_neurons, 0);
    for (int i = 0; i < num_neurons; i++)
    {
        outputs[i] = thisLayer[i]->ActivateFunction(inputs[i]);
    }
}

void Layer::forward_propagate()
{
    calc_inputs();
    calc_outputs();
}

void Layer::calc_deltas()
{
    if (indice > 0)
    {
        deltas = Vector(num_neurons, 0);
        if (indice == network->topology.size() - 1)
        {
            Vector targets = network->get_targets();
            for (int i = 0; i < num_neurons; i++)
            {
                deltas[i] = thisLayer[i]->D_ActivateFunction(inputs[i]) * (outputs[i] - targets[i]);
            }
        }
        else
        {
            Matrix next_weights = Transpose(network->get_layer_at(indice + 1)->get_weights());
            Vector next_deltas = network->get_layer_at(indice + 1)->get_deltas();
            deltas = MultMatVec(next_weights, next_deltas);
            for (int i = 0; i < deltas.size(); i++)
            {
                deltas[i] *= thisLayer[i]->D_ActivateFunction(inputs[i]);
            }
        }
    }
}

void Layer::calc_new_weights()
{
    if (indice > 0)
    {
        double eta = 0.005;
        Vector prev_outputs = network->get_layer_at(indice - 1)->get_outputs();
        for (int i = 0; i < weights.size(); i++)
        {
            for (int j = 0; j < weights[i].size(); j++)
            {
                weights[i][j] -= eta * deltas[i] * prev_outputs[j];
            }
        }
    }
}

void Layer::back_propagate()
{
    calc_deltas();
    calc_new_weights();
}