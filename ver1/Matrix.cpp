#include "Matrix.hpp"

Vector MultMatVec(Matrix M, Vector V)
{
    int rowN = M.size();
    int colN = M[0].size();
    int vecN = V.size();
    if (colN != vecN)
    {
        cout << "error" << endl;
        exit(0);
    }
    Vector out = Vector(rowN, 0);

    for (int i = 0; i < rowN; i++)
    {
        for (int j = 0; j < colN; j++)
        {
            out[i] += M[i][j] * V[j];
        }
    }

    return out;
}