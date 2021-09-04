#include "NeuralNetwork.hpp"

// First number is input number (without bias), the last number is output number,
// and the other numbers is hidden layer numbers (without bias).
vector<unsigned int> topology{2, 3, 1};

// Epoch
int epoch = 1000000;

int main()
{
    NeuralNetwork nn(topology);

    // Main train loop
    // for (int t = 0; t < epoch; t++)
    // {
    // }

    // test //
    Vector b{0, 0};
    Vector c = nn.Feedforward(b);
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << endl;
    }
    Vector train_output{0};
    nn.Backpropagation(train_output);
}