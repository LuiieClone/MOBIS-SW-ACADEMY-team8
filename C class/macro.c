#include <stdio.h>

int main()
{
	printf("Time: %s, %s\n",__DATE__, __TIME__);
	printf("File name: %s\n",__FILE__ );
	printf("Function Name: %s\n",__FUNCTION__);
	printf("Line number: %d\n",__LINE__);
    return 0;
}


