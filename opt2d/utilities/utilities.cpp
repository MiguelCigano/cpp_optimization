#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "..\linalg\linalg.h"
#include "utilities.h"

using namespace std;

void mostrarEstado(double cont, Matrix x, double Ux, Matrix dUx, ios::fmtflags settings)
{
    double x1 = x.getValue(0,0);
    double x2 = x.getValue(0,1);
    double norma = normaM(dUx);

    cout.flags(settings);
    cout << setw(3) << cont << '\t';
    cout << scientific << setprecision(6) << setfill(' ');
    cout << x1 << "\t" << x2 << "\t" << Ux << "\t" << norma << endl; 
}

void guardarRegistro(Matrix registro)
{
    ofstream myfile;
    myfile.open("data.csv");

    myfile << "cont,x1,x2,cost," << endl; 

    for (int i = 0; i < registro.Rows(); i++)
    {
        for (int j = 0; j < registro.Columns(); j++)
        {
            myfile << registro.getValue(i,j) << ",";
        }

        myfile << endl;
    }

    myfile.close();
        
}