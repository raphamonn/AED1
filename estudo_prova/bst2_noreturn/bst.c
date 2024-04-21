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

int tree_height(Node * root){
    if (root == NULL){
        return -1;
    }
    else {
        int left = tree_height(root->left);
        int right = tree_height(root->right);

        if(left > right)
            return left + 1;
        else 
            return right + 1;
    }
}

int tree_nodes (Node* root){
    if (root == NULL){
        return 0;
    }
    else {
        return 1 + tree_nodes(root->left) + tree_nodes(root->right);
    }
}


int count_sheets (Node * root){
    if (root == NULL){
        return 0;
    }
    else if (root->left == NULL && root->right == NULL){
        return 1;
    }
    else 
        return count_sheets(root->left) + count_sheets(root->right);
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

Node * remove_node (Node * root, int num){
    printf("%d ", root->value);
    if (root == NULL){
        printf("\nO nó não esá presente na arvore\n");
        return NULL;
    } else {
        if (root->value == num){
            // remover o nó se ele for um nó folha
            if(root->left == NULL && root->right == NULL){
                free(root);
                printf("\nbucetinha de cocô\n");
                return NULL;
            }
            else {
                // nó com filhos
                printf("este nó possui filhos, não podemos deixa-los orfãos");
            }
        } else {
            if (num < root->value)
                root->left = remove_node(root->left, num);
            else
                root->right = remove_node(root->right, num);
            return root;
        }
    }
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
        printf("\nO nó está presente na árvore e é %d \n", search_node->value);   
    }
    else {
        printf("\nO nó não está presente na árvore\n");
    }
    
    printf("\nA altura da árvore é: %d\n", tree_height(root));
    printf("\nQuantidade de folhas é: %d\n", count_sheets(root));

    root = remove_node(root,10);

    print_tree(root);
    printf("\n");
    return 0;
}
