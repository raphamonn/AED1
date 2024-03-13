#include <stdio.h>

#include "linked_list.h"

int main() {

    LinkedList* lista = list_create();

    list_insertFirst(lista, 2); 

    list_print(lista);
    return 0;
}