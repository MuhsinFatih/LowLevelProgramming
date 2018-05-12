#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy
#include "colorprint.h"

int main() {
    {
        // allocating
        char* str = (char*) malloc(15);
        strcpy(str, "muhsinfatih");
        printf(GREEN "string: %s," YELLOW " address: %u\n", str, str);

        // reallocating
        str = (char*) realloc(str, 25);
        strcat(str, ".com");
        printf(GREEN "string: %s," YELLOW " address: %x\n", str, str);
        free(str);
    }
    {
        char* str = (char*) malloc(100);
        printf(RESET);
        memset(str, 'a', 100);
        free(str); // move the stack pointer back
        str = (char*) malloc(100); // allocate again
        printf(MAGENTA "malloc overwrite: %s\n", str);

        str = (char*) calloc(100, 1); // or calloc(100, sizeof(char)), but char is always of size 1 by definition
        printf(MAGENTA "calloc overwrite: %s\n", str);
    }


    return 0;
}