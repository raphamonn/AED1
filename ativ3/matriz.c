#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz {
    double** array;
    int rows;
    int cols;
};

Matriz* matriz_create(int rows, int cols) {
    Matriz* matriz = malloc(sizeof(Matriz));

    matriz->array = malloc(sizeof(double*) * rows);
    for (int i = 0; i < rows; i++) {
        matriz->array[i] = malloc(sizeof(double) * cols);
    }
    matriz->rows = rows;
    matriz->cols = cols;

    return matriz;
}

void matriz_destroy(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        free(matriz->array[i]);
    }
    free(matriz->array);
    free(matriz);
}

void matriz_print(Matriz* matriz) {
    for (int i = 0; i < matriz->rows; i++) {
        for (int j = 0; j < matriz->cols; j++) {
            printf("%.4f ", matriz->array[i][j]);
        }
        printf("\n");
    }
}

double matriz_get(Matriz* matriz, int row, int col) {
    return matriz->array[row][col];
}

void matriz_set(Matriz* matriz, int row, int col, double value) {
    matriz->array[row][col] = value;
}

int matriz_rows(Matriz* matriz) {
    return matriz->rows;
}

int matriz_cols(Matriz* matriz) {
    return matriz->cols;
}

bool matriz_equals(Matriz* matriz1, Matriz* matriz2) {
    if (matriz1->rows != matriz2->rows || matriz1->cols != matriz2->cols) {
        return false;
    }

    for (int i = 0; i < matriz1->rows; i++) {
        for (int j = 0; j < matriz1->cols; j++) {
            if (matriz1->array[i][j] != matriz2->array[i][j]) {
                return false;
            }
        }
    }

    return true;
}

Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2){
    
    if (matriz1->rows != matriz2->rows ||  matriz1->cols != matriz2->cols){
        return NULL;
    }

    int cols = matriz1->cols;
    int rows = matriz1 -> rows;

    Matriz* new_matriz = matriz_create(rows,cols);

    for (int i=0; i < rows; i++){
        for (int j=0; j<cols; j++){
            new_matriz->array[i][j] = matriz1->array[i][j] + matriz2->array[i][j];
        }
    }



    return new_matriz;
}

Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2){
    if (matriz1->rows != matriz2->rows ||  matriz1->cols != matriz2->cols){
        return NULL;
    }

    int cols = matriz1->cols;
    int rows = matriz1 -> rows;

    Matriz* new_matriz = matriz_create(rows,cols);

    for (int i=0; i < rows; i++){
        for (int j=0; j<cols; j++){
            new_matriz->array[i][j] = matriz1->array[i][j] - matriz2->array[i][j];
        }
    }   
    return new_matriz;
}


Matriz* matriz_scalar_mul(Matriz* matriz, double scalar){
    if (matriz->rows != matriz->cols){
        return NULL;
    }
    
    Matriz* new_matriz = matriz_create(matriz->rows,matriz->cols);
    
    for (int i=0; i < matriz->rows; i++){
        for (int j=0; j<matriz->cols; j++){
            new_matriz->array[i][j] = matriz->array[i][j] * scalar; 
        }
    }   
    return new_matriz;  
}


Matriz* matriz_transpose(Matriz* matriz){

    Matriz* new_matriz = matriz_create(matriz->cols,matriz->rows);

    for (int i=0; i < matriz->rows; i++){
        for (int j=0; j<matriz->cols; j++){
            new_matriz->array[j][i] = matriz->array[i][j];
        }
    }
    return new_matriz;    
}

bool matriz_is_symmetric(Matriz* matriz){
    Matriz* transposed = matriz_transpose(matriz);

    if (matriz_equals(matriz,transposed)){
        matriz_destroy(transposed);
        return true;
    }
    else{
        matriz_destroy(transposed);
        return false;
    }
}
