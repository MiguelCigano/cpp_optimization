#include "../linalg/linalg.h"
#include "../linalg/matrix.h"
#include <math.h>
#include <problem.h>

double cost_fn(Matrix x)
{
    double x1 = x.getValue(0,0);
    double x2 = x.getValue(0,1);

    return -(20*x1) -  (40*x2) + 90*pow(pow(pow(x1,2) + pow(x2-1,2),0.5)-1,2) + 100*pow(pow(pow(x1,2) + pow(x2+1,2), 0.5)-1,2);
}

Matrix cost_fn_gradient(Matrix x, double deltaX)
{
    Matrix vecX1(1,2);
    Matrix vecX2(1,2);
    Matrix deriv(1,2);
    for (int i = 0; i < x.Columns(); i++) {
        vecX1 = x;
        vecX2 = x;
        vecX1.setValue(0,i,x.getValue(0,i) + deltaX);
        vecX2.setValue(0,i,x.getValue(0,i) - deltaX);
        deriv.setValue(0,i,(cost_fn(vecX1) - cost_fn(vecX2)/(2*deltaX)));
    }

    return deriv;
}