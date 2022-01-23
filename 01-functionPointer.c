#include <stdio.h>
#include <stdlib.h>

/*
 Define data_type of type function_pointer named fnptr_t 
 fntpr_t which will point to the function which rerturns pointer to the int
 and taked two integer pointers as function parameters
*/
typedef int* (*fnptr_t)(int *, int *);

int sum;

int*
fnsum (int *x, int *y) {
	sum = *x + *y;
	return &sum;
}

int 
main()
{
	int *pSum;
	int x = 5;
	int y = 10;

	fnptr_t fnptr; // function_pointer
	fnptr_t *fnptrptr; // pointer to the function_pointer
	fnptr = &fnsum;
	fnptrptr = &fnptr;
	pSum = fnptr(&x, &y); // invoke function pointed by fnptr
	printf("sum = %d\n", *pSum); 

	pSum = (*fnptrptr)(&x, &y); // invoke pointed by content of fnptrptr
	printf("sum = %d\n", *pSum); 
	return 0;
}
