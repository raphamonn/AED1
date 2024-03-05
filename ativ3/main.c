#include <stdio.h>

#include "matriz.h"

int main(void) {
    
    Matriz* matriz1 = matriz_create(3,4);
    
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            matriz_set(matriz1,i,j,i);
        }
    }    

    matriz_print(matriz1);

    matriz1 = matriz_transpose(matriz1);

    matriz_print(matriz1);
    
    matriz_destroy(matriz1);

}
