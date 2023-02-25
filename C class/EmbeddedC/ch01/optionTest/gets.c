#include <stdio.h>
#include <string.h>

int main()
{
	char str[10];

	printf("string: \n");
	//gets(str);
	fgets(str, 80, stdin);
	//str[sizeof(str)-1]
	str[strlen(str)-1] = '\0'; //Delete 'n'
	return 0;
}


