#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* cptr = malloc(sizeof(char)*30);
    if(cptr == NULL){
        fprintf(stderr, "cannot allocate memory\n");
        exit(1);
    }

    strcpy(cptr, "HELLO!");
    printf("%s\n", cptr);

    free(cptr);
    return 0;
}
