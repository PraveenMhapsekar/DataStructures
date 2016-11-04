#include <stdio.h>
#include <stdlib.h>

typedef int* (*fnptr_t)(int *, int *);

int sum;

int*
fnsum (int *x, int *y) 
{
    sum = *x + *y;
    return &sum;
}

int 
main()
{
    int *pSum;
    int x = 5;
    int y = 10;

    fnptr_t fnptr;
    fnptr_t *fnptrptr;
    fnptr = &fnsum;
    fnptrptr = &fnptr;
    pSum = fnptr(&x, &y);
    printf("sum = %d\n", *pSum); 

    pSum = (*fnptrptr)(&x, &y);
    printf("sum = %d\n", *pSum); 
    return 0;
}
