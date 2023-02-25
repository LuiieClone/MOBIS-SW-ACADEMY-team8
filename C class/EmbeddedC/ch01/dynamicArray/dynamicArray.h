#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

typedef struct darray {
	int max_size;
	int size;
	void** array;
} darray;


// 함수 원형 선언 
int createArray(darray** lpArray);
int destroyArray(darray* lpArray);
int AddArray(darray* lpArray, void** value);
/* 
   lpArray :배열의 시작 주소
   value : 배열에 등록할 값  
*/

int GetArray(darray* lpArray,int i,void** value);
/* 
	lpArray :배열의 시작 주소
	i : 배열의 위치
	value : 배열에 있는 원소값
*/
#endif
