// 동적 배열 구성하기
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

int main()
{
	darray *lpArray=NULL;

	 if(!createArray(&lpArray)) {		// 배열 선언 
		fprintf(stderr, "%s %d\n", __FILE__, __LINE__);
		return 1;
	}

	int i;

	for(i=0; i<50; i++) 
	//for(i=0; i<5; i++) 
		AddArray(lpArray, i+1);		// 원소 추가 
		

	int value;

	for(i=0; i<50; i++) {
	//for(i=0; i<5; i++) {
		GetArray(lpArray, i, &value);
		printf("%d\n", value);
	}

	destroyArray(lpArray);
 
	return 0;
}

