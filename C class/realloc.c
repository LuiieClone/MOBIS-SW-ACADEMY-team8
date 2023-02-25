#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* cptr = (char*) malloc(sizeof(char)*10);
	if(cptr == NULL){
		fprintf(stderr, "cannot allocate memory\n");
		exit(1);
	}
	
	strcpy(cptr, "HELLO!");
	printf("%s\n", cptr);
	
	cptr = (char*) realloc(cptr, sizeof(char)*30);
	strcat(cptr, "Embedded C");
	printf("%s\n", cptr);

	free(cptr);

	return 0;
}

