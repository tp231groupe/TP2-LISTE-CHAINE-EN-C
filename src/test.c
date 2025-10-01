#include <stdio.h>
#include <stdlib.h>
#include "../lib/utils.h"
#include "../lib/operations.h"
#include "../lib/matrices.h"


void printVector(int* v, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printMatrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void testVectors() {
    printf("=== TEST VECTEURS ===\n");

    int v1[5] = {1, 2, 3, 4, 5};
    int v2[5] = {5, 4, 3, 2, 1};

    printf("Recherche de 3 dans v1 : index = %d\n", linearSearch(v1, 5, 3));
    printf("Recherche de 7 dans v1 : index = %d\n", linearSearch(v1, 5, 7));

    printf("Statut tri de v1 : %d\n", sortStatus(v1, 5));
    printf("Statut tri de v2 : %d\n", sortStatus(v2, 5));

    int* reversed = reverseArray(v1, 5);
    printf("v1 inversé : ");
    printVector(reversed, 5);
    free(reversed);

    int* product = vectorProduct(v1, v2, 5, 5);
    printf("Produit Hadamard v1 * v2 : ");
    printVector(product, 5);
    free(product);
}


void testMatrices() {
    printf("\n=== TEST MATRICES ===\n");


    int** A = malloc(2 * sizeof(int*));
    int** B = malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        A[i] = malloc(2 * sizeof(int));
        B[i] = malloc(2 * sizeof(int));
    }

  
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    printf("Matrice A:\n"); printMatrix(A, 2, 2);
    printf("Matrice B:\n"); printMatrix(B, 2, 2);

    int** S = sum(A, B, 2, 2, 2, 2);
    printf("A + B:\n"); printMatrix(S, 2, 2);

    int** P = product(A, B, 2, 2, 2, 2);
    printf("A * B:\n"); printMatrix(P, 2, 2);

    int** SM = scalarMultiply(A, 2, 2, 2);
    printf("2 * A:\n"); printMatrix(SM, 2, 2);

    int** Pos = positiveProduct(A, B, 2, 2, 2, 2);
    printf("Produit positif Hadamard (A,B):\n"); printMatrix(Pos, 2, 2);

  
    for (int i = 0; i < 2; i++) {
        free(A[i]); free(B[i]); free(S[i]); free(P[i]); free(SM[i]); free(Pos[i]);
    }
    free(A); free(B); free(S); free(P); free(SM); free(Pos);
}


int main() {
    testVectors();
    testMatrices();
    //printf("hello world");
    return 0;
}
