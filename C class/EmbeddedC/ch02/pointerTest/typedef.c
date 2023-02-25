#include <stdio.h>

int main()
{
    typedef unsigned int uint;
    typedef struct {
        char name[20];
        int age;
        float height;
    } aaa;

    aaa person[100];

    uint num;

    printf("input : ");
    scanf("%d", &num);
    printf("%u\n", num);

    return 0;
}