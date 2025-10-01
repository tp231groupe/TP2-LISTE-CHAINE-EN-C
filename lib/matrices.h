#ifndef MATRICES_H
#define MATRICES_H
int** sum(int** arrayA, int** arrayB, int rowsA,int colsA,int rowsB, int colsB);
int** product(int** arrayA, int** arrayB, int rowsA,int colsA,int rowsB, int colsB);
int** scalarMultiply(int** arrayA, int rows, int cols, int m);
int** positiveProduct(int** arrayA, int** arrayB, int rowsA, int colsA, int rowsB, int colsB);
#endif