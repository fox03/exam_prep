#include "t2q4.h"

int main(void)
{
    Set** mystruct;
    int size;

    mystruct = readFile("file.txt", &size);

    printf("%d\n", size);


    return(0);
}
