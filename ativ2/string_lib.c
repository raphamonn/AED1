#include "string_lib.h"

#include <stdio.h>
#include <stdlib.h>

String* string_create(char* data, int length) {
    String* str = malloc(sizeof(String));

    str->data = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        str->data[i] = data[i];
    }

    str->length = length;

    return str;
}

void string_destroy(String* str) {
    free(str->data);
    free(str);
}

void string_print(String* str) {
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

String* string_reverse(String* str) {
    String* reversed = string_create(str->data, str->length);
    
    for (int i = 0, j = str->length-1; i < j; i++, j--) {
        char temp = reversed->data[i];
        reversed->data[i] = reversed->data[j];
        reversed->data[j] = temp;
    }

    return reversed;
}


void string_append(String *str1, String* str2) {
    int new_len = str1-> length + str2-> length; 

    char* appended_string = malloc(new_len * sizeof(char)); 
    
    for (int i=0; i<str1->length; i++){
        appended_string[i] = str1->data[i];
    }

    for (int i= 0; i<str2->length; i++){
        appended_string[i+str1->length] = str2->data[i];
    }    

    free(str1->data);

    str1->data = appended_string;
    str1->length = new_len;
}