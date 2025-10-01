#include "../lib/utils.h"
#include "../lib/matrices.h"

int** sum(int** arrayA, int** arrayB, int rowsA, int colsA, int rowsB, int colsB){
    if(!canAddorSubstract(rowsA, colsA, rowsB, colsB)){
        printf("Erreur : dimensions incompatibles pour la somme.\n");
        return NULL;
    }
    
    int** result = malloc(rowsA *sizeof(int*));

    for(int i = 0; i < rowsA; i++){
        result[i] = malloc(colsA * (sizeof(int)));
        if (result[i] == NULL) 
            return NULL; 
    }

    for (int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++)
            result [i][j] = arrayA[i][j] + arrayB[i][j];
    }
    
    return result;
}

int** product(int** arrayA, int** arrayB, int rowsA, int colsA, int rowsB, int colsB){

    if(canMultiply(rowsA, colsA, rowsB, colsB)){
        printf("Erreur : dimensions incompatibles pour la somme.\n");
        return NULL;
    }
    
    int** result = malloc(rowsA * sizeof(int*));

    for(int i = 0; i < rowsA; i++){
        result[i] = malloc(colsA * (sizeof(int)));
        if (result[i] == NULL) 
            return NULL; 
        for(int j = 0; j < colsB; j++)
            result[i][j] = 0;
    }

    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            for(int k = 0; k < colsA; k++){
                result[i][j] += arrayA[i][j] * arrayB[j][k];
            }
        }
    }
} 

int** scalarMultiply(int** array, int rows, int cols, int m ){
    int** result = malloc(rows * sizeof(int*));
    
    for(int i = 0; i < cols; i++){
        result[i] = malloc(cols * sizeof(int));
        if(result[i] == NULL)
            return NULL;
    }

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = array[i][j] * m;
        }
    }

    return result;
}

int** positiveProduct(int** arrayA, int** arrayB, int rowsA, int colsA, int rowsB, int colsB){
    
    if(canMultiply(rowsA, colsA, rowsB, colsB)){
        printf("Erreur: dimension incompatible avec le produit");
        return NULL;
    }

    int** result = malloc(rowsA * sizeof(int* ));
    for(int i = 0; i < colsB; i++){
        result[i] = malloc(colsB * sizeof(int));
        if(result[i]==NULL)
            return NULL;

        for(int j = 0; j < colsB; j++){
            if(arrayA[i][j] * arrayB[i][j] > 0)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    }

    return result;
}