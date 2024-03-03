#include <stdio.h>
#include "string_lib.h"

int main(void) {
    
    String* string1 = string_create("ola", 3);

    String* string2 = string_create(" mundo", 6);

    
    String* reverse = string_reverse(string1);

    string_print(string1);   

    string_print(reverse); 
}
