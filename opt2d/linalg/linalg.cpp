#include <iostream>
#include <vector>
#include <cmath>

#include "matrix.h"
#include "linalg.h"

using namespace std;

void 
imprimeMatriz(Matrix x)
{
    for(int i = 0; i < x.Rows(); i++){
        for(int j = 0; i < x.Columns(); i++){
            std::cout << x.getValue(i,j) << '\t';
        }
        std::cout << std::endl;
    }
}

double 
normaMatriz(Matrix x)
{
    double x1 = x.getValue(0,0);
    double x2 = x.getValue(0,1);
    return sqrt(pow(x1, 2) + pow(x2, 2));
}

Matrix inversaMatriz(Matrix x)
{
    double a = x.getValue(0,0);
    double b = x.getValue(0,1);
    double c = x.getValue(1,0);
    double d = x.getValue(1,1);
    Matrix y({{d,-b}, {-c,a}});
    double determinante = 1/(a*d -b*c);
    for(int i = 0; i < y.Rows(); i++){
        for(int j = 0; i < y.Columns(); j++){
            y.setValue(i,j, determinante*y.getValue(i,j));
        }
    }
    return y;
}

Matrix transMatriz(Matrix x)
{
    Matrix y(x.Columns(), x.Rows());
    for(int i = 0; i < y.Rows(); i++){
        for(int j = 0; j < y.Columns(); j++){
            y.setValue(i, j, x.getValue(j,i));
        }                           
    }
    return y;
}

Matrix multEM(double x, Matrix y)
{
    Matrix z(y.Rows(), y.Columns());
    for (int i = 0; i < z.Rows(); i++){
        for (int j = 0; j < z.Columns(); j++){
            z.setValue(i, j, x*y.getValue(i,j));
        }
    }
    return z;
}

