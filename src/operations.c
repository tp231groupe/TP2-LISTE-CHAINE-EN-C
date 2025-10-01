#include "../lib/operations.h"
#include "../lib/utils.h"

int linearSearch(int* array,int size, int element){

    if(!canSearch(array,size)){
        printf("Erreur: impossible d'effectuer la recherche,vecteur mal definis");
        return -1;
    }

    for(int i = 0; i < size; i++){
        if(array[i] == element)
            return 1;
    }

    return 0;

}

int sortStatus(int* array, int size){
    int ascending = 1, descending = 1;

    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            ascending = 0;
        }
        if (array[i] < array[i + 1]) {
            descending = 0;
        }
    }

    if (ascending) return 1;
    if (descending) return -1;
    
    return 0;
}

int* reverseArray(int* array, int size){
  
    if(!canReverse(array, size)){
        printf("Erreur: impossible d'effectuer, vecteur mal definis");
        return 0;
    }

    int* reversedArray = malloc(size * sizeof(int));
    if(reversedArray == NULL){
        printf("Erreur lors de la creation du vecteur");
        return NULL;
    }     

    for(int i = size - 1; i > 0; i--)
        reversedArray[i] = array[i];
    
    return reversedArray;

}

int* vectorProduct(int* arrayA, int* arrayB, int sizeA, int sizeB){

    int* result = malloc(sizeA * sizeof(int));

    if (result == NULL) 
        return NULL;
    
    for (int i = 0; i < sizeA; i++) {
        result[i] = arrayA[i] * arrayB[i];
    }

    return result;
}