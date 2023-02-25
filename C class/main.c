#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc != 2 )
	{
		printf("%s port number\n", argv[0]);
		exit(1);
	}
	
	int portnum = atoi(argv[1]);
	printf("port number: %d\n", portnum);

	return 0;
}
