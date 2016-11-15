#include "t2q4.h"

Set** readFile(char* file, int* size)
{
    FILE* f;
    int i, lines, length;
    Set** mystruct;
printf("here\n");
    f = fopen(file, "r");

    if(f != NULL)
    {
        fscanf(f, "%d %d", &lines, &length);
        *size = lines;

        printf("%d %d\n", lines, length);

        mystruct = (Set**)malloc(lines * sizeof(Set*));

        for(i=0; i<lines; i++)
        {
            char* text = (char*)malloc(length * sizeof(char));
            printf("here2\n");
            fflush(stdout);
            fscanf(f, "%c %s", mystruct[i].search, text);
            printf("here3\n");
            fflush(stdout);
            mystruct[i].text = text;
        }
    }
    else
    {
        mystruct = NULL;
    }

    return(mystruct);
}
