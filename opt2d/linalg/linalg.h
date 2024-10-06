#pragma once
/*
Es una directiva de preprocesador en c++ que se utiliza para asegurarse de que un archivo de encabezado se incluya
solo una vez durante la compilación.
Evitando así problemas de inclusiones multiples y duplicaciones de simbolos.

Cuando un archivo de encabezado es incluido en varios archivos de codigo fuente, puede causar errores de compilacion debido a la redefinicion de clases, funciones, o variables. Con #pragma once se previene este problema.
*/

# include "matrix.h"

void imprimeMatriz(Matrix x);
double normaMatriz(Matrix x);

Matrix inversaMatriz(Matrix x);
Matrix transMatriz(Matrix x);
Matrix multiEM(double x, Matrix y);
