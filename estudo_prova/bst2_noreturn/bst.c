#include <stdio.h>
#include <stdlib.h>

typedef struct bst { 
    int value;
    struct bst *left, *right;
} Node; 


Node* insert_into_tree_v1(Node* root, int num){
    if (root == NULL) {
        Node * new_node = malloc(sizeof(Node));
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = num;
        return new_node;
    }   
    else{
        if (num < root->value){
            root->left = insert_into_tree_v1(root->left, num);
        }
        else {
            root->right = insert_into_tree_v1(root->right, num);
        }
        return root;
    }
}


void insert_into_tree_v2(Node **root, int num){
    if (*root == NULL){
        *root = malloc(sizeof(Node));
        (*root)->value= num;
        (*root)->left = NULL;
        (*root)->right = NULL;

    }
    else{
        if (num < (*root)->value){
            insert_into_tree_v2(&((*root)->left), num);
        }
        else {
            insert_into_tree_v2(&((*root)->right), num);
        }
    }
}

void print_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

Node * search_in_tree_v1(Node * root,int num) {
    if (root){
        if(num == root->value) {
            return root;
        }
        else if (num < root->value){
            return search_in_tree_v1(root->left, num);
        }
        else {
            return search_in_tree_v1(root->right, num);
        }
    }
    return NULL;
}



int main () {

    Node* root = NULL;

    
    insert_into_tree_v2(&root, 3);
    insert_into_tree_v2(&root, 2);
    insert_into_tree_v2(&root, 1);
    insert_into_tree_v2(&root, 10);
    print_tree (root);
    printf("\n");
    Node * search_node = search_in_tree_v1(root, 15);
    if (search_node){ 
        printf("O nó está presente na árvore e é %d ", search_node->value);   
    }
    else {
        printf("O nó não está presente na árvore");
    }
    
    return 0;
}
