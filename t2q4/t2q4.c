#include "t2q4.h"

Set** readFile(char* file, int* size)
{
    FILE* f;
    int i, lines, length;
    Set** mystruct;
    f = fopen(file, "r");


    if(f != NULL)
    {

        fscanf(f, "%d %d\n", &lines, &length);
        *size = lines;
        printf("%d %d\n", lines, length);

        /* This allocates memory for a series of pointers to structs ie. an array*/
        mystruct = (Set **)malloc(lines * sizeof(Set*));
        /* This allocates memory for the structs those pointers point to ie. the elements of the array*/
        /* This is the key part of the code that was missing */
        for (i = 0; i < lines; i++) {
          mystruct[i] = malloc(sizeof(Set));
        }

        for(i = 0; i < lines; i++)
        {
            /* Allocate memory for string in the struct */
            mystruct[i]->text = (char*)malloc(length * sizeof(char));
            /* Read from file into struct */
            fscanf(f, "%c %s\n", &mystruct[i]->search, mystruct[i]->text);
        }

        /* Check everything went into the struct array fine */
        for(i = 0; i < lines; i++)
        {
          printf("%c %s\n", mystruct[i]->search, mystruct[i]->text);
        }

        /* Free the memory used */
        for(i = 0; i < lines; i++)
        {
          free(mystruct[i]->text);
          free(mystruct[i]);
        }
        free(mystruct);

    }
    else
    {
        mystruct = NULL;
    }

    fclose(f);

    return(mystruct);
}
