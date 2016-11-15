#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char search;
    char *text;
}Set;

Set** readFile(char* file, int* size);
