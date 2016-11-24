#include <stdio.h>

int
multOf(int i, int j)
{
    return ((i % j) == 0);
}

void
fizzbuzz(int i)
{
    if (multOf(i, 15)) {
        printf("fizzbuzz\n");
    } else if (multOf(i, 3)) {
        printf("fizz\n");
    } else  if (multOf(i, 5)) {
        printf("buzz\n");
    } else {
        printf("%d\n", i);
    }
}

int
main(void) 
{
   int i;

   for (i = 0; i < 100; i++) {
       fizzbuzz(i);
   }
}

  
