#ifndef __Matrix__
#define __Matrix__

#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector MultMatVec(Matrix M, Vector V);

#endif