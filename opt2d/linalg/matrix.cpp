#include <iostream>
#include <vector>

#include <matrix.h>


Matrix::Matrix()
{
}

Matrix::Matrix(int rows, int columns)
{
    vector<vector<double>> aux(rows, vector<double>(columns, 0));
    data = aux;
}

Matrix::Matrix(vector<vector<double>> aux)
{
    data = aux;
}

int Matrix::Rows()
{
    return data.size();
}

int Matrix::Columns()
{
    return data[0].size();
}

double Matrix::getValue(int i, int j)
{
    return data[i][j];
}

void Matrix::setValue(int i, int j, double aux)
{
    data[i][j] = aux;
}

void Matrix::addValue(vector<double> aux)
{
    data.push_back(aux);
}

/* se agrega sobre row and columns */

Matrix Matrix::getRows(int i)
{
    int columns = data[i].size();
    Matrix aux(1, columns);
    for(int j = 0; j < columns; j++){
        aux.setValue(0, j, data[i][j]);
    }
    return aux;
}

void Matrix::setRows(int i, Matrix x)
{
    for(int j = 0; j < x.Columns(); j++){
        data[i][j] = x.getValue(0, j);
    }
}

Matrix Matrix::getColumns(int i)
{
    int rows = data.size();
    Matrix aux(rows, 1);
    for(int j =0; j < rows; j++){
        aux.setValue(j, 0, data[i][j]);
    }
    return aux;
}

void Matrix::setColumns(int i, Matrix x)
{
    for(int j = 0; j < x.Rows(); j++){
        data[i][j] = x.getValue(j, 0);
    }
}
