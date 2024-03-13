#include <stdio.h>

#include "sorted_list.h"

int main(void) {
    SortedList* list = slist_create();

    bool success;

    success = slist_insert(list, 123, "Alice", 9.0);
    if (success) {
        printf("Inserção bem-sucedida: RA 123\n");
    } else {
        printf("Falha na inserção: RA 123 já existe\n");
    }    


    success = slist_insert(list,123, "Rafael", 10);
    if (success) {
        printf("Inserção bem-sucedida: RA 123\n");
    } else {
        printf("Falha na inserção: RA 123 já existe\n");
    }    

    return 0;
}
