#include <stdio.h>

void selection_sort(int * v, int tam){
    int i,j,min;

    for (i=0; i<tam; i++){
        min = i; //assume que a primeira posíção é a menor

        for(j=i+1; j<tam; j++){
            if(v[j]<v[i]){
                min = j;
            }    
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux; 
        }
    }
}

int main () {
    int vetor[5] = {4,70,6,3,1};
    printf("\n%d\n",vetor[1]);

    selection_sort(vetor, 5);
    
    for (int i=0; i<5; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}