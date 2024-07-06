#include <iostream>
#include <vector>

#include "matrix.h"
#include "linalg.h"

using namespace std;

void imprimeMatriz(Matrix x)
{
    for(int i = 0; i < x.Rows(); i++)
    {
        for(int j = 0; i < x.Columns(); i++)
        {
            std::cout << x.getValue(i,j) << '\t';
        }
        std::cout << std::endl;
    }
}

double Norma(Matrix x)
{
    double x1 = x.getValue(0,0);
    double x2 = x.getValue(0,1);

    return sqrt(pow(x1, 2) + pow(x2, 2));
}

Matrix invertidaMatriz(Matrix x)
{
    double a = x.getValue(0,0);
    double b = x.getValue(0,1);
    double c = x.getValue(1,0);
    double d = x.getValue(1,1);

    Matrix y({{d,-b}, {-c,a}});
    double determinante = 1/(a*d -b*c);

    for(int i = 0; i < y.Rows(); i++)
    {
        for(int j = 0; i < y.Columns; j++)
        {
            y.setValue(i,j, determinante*y.getValu(i,j));
        }
    }
    return y;
}


