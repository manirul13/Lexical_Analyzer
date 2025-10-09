#include <stdio.h>
void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main()
{
    int a = 10, b = 20;

    scanf("%d %d", &a, &b);
    printf("Beofre swapping: a=%d, b=%d\n", a, b);

    swap(&a, &b);

    printf("After swapping: a=%d, b=%d\n", a, b);

    return 0;
}