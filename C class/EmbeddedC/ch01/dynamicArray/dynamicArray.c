// 동적 배열 구성하기
#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

int createArray(darray** lpArray)
{
	darray* temp;

	temp = (darray *)malloc(sizeof(darray));
	if(temp==NULL)
		return 0;
	temp->max_size=10;
	temp->size=0;
	temp->array = (void *) malloc(sizeof(void*)*temp->max_size);
	if(temp->array==NULL)
		return 0;
	*lpArray = temp;
	return 1;
}

int destroyArray(darray* lpArray)
{
	free(lpArray);
	return 1;
}

int AddArray(darray* lpArray, void* value)
{
	if(lpArray->size==lpArray->max_size) { 		// Full?
		lpArray->array=(void**)realloc(lpArray->array, sizeof(void*) * lpArray->max_size*2);
		if(lpArray->array==NULL) {
			perror("Memory Realloc");
			return 0;
		}
		lpArray->max_size *= 2;
	}
		
	lpArray->array[lpArray->size++]=*value;
	return 1;
}


int GetArray(darray*lpArray,int i,void** value)
{
	if(i>=lpArray->max_size)
		return 0;
	*value = lpArray->array[i];
	return 1;
}
