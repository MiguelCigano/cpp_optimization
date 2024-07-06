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
    
}