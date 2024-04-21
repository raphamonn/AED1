#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int valor;
    struct node *left, *right;

} NodeTree;


NodeTree* insert_into_treef(NodeTree *raiz, int num){
   if (raiz == NULL){
        NodeTree *aux = malloc(sizeof(NodeTree));
        aux->valor = num;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
   }
   else {
        if (num < raiz->valor)
            raiz->left = insert_into_tree(raiz->left, num);
        else 
            raiz->right = insert_into_tree(raiz->right, num);
        return raiz;
    } 
}

void print_tree_v1(NodeTree *raiz){
    
    if (raiz){
        printf("%d ", raiz->valor);
        print_tree_v1(raiz->left);
        print_tree_v1(raiz->right);
    }
}

void print_tree_v2(NodeTree *raiz){
    
    if (raiz){   
        print_tree_v2(raiz->left);
        printf("%d ", raiz->valor);
        print_tree_v2(raiz->right);        
    }
}



int main () {
    NodeTree *raiz =  NULL;
    
    raiz = insert_into_tree(raiz, 10);
    raiz = insert_into_tree(raiz, 25);
    raiz = insert_into_tree(raiz, 5);
    raiz = insert_into_tree(raiz,100);
    raiz = insert_into_tree(raiz,23);
    raiz = insert_into_tree(raiz,42);
    raiz = insert_into_tree(raiz,30);
    raiz = insert_into_tree(raiz,70);

    printf("\n");
    print_tree_v1(raiz);
    printf("\n");
    print_tree_v2(raiz);
    printf("\n");

    return 0;            
}

