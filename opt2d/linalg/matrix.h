#pragma once

#include <vector>

using namespace std;

class Matrix
{
    private:
        vector<vector<double>> data;

    public:
        Matrix();
        Matrix(int Rows, int Columns);
        Matrix(vector<vector<double>> aux);

        int Rows();
        int Columns();

        double getValue(int i, int j);
        void setValue(int i, int j, double aux);
        void addValue(vector<double>);
        
        Matrix getRows(int i);
        void setRows(int i, Matrix x);
        Matrix getColumns(int i);
        void setColumns(int i, Matrix x);
};