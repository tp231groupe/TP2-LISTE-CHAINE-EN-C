#include "../lib/utils.h"

int canAddorSubstract(int rowsA, int colsA, int rowsB, int colsB){
    return (rowsA == rowsB && colsA ==  colsB);
}

int canMultiply(int rowsA, int colsA, int rowsB, int colsB){
    return (colsA == rowsB);
}

int canSearch(int* array, int size){
    return (array != NULL && size > 0); 
}

int canReverse(int* array, int size){
    return (array != NULL && size > 0);
}