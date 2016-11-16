#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int N = 0x12343412;
    char *l = (char *)&N;
    char *r = l + (sizeof(int) - 1);


    printf("size of int %ld\n", sizeof(int));
    printf("size of long %ld\n", sizeof(long));
    while (l < r) {
        if (*l ^ *r) {
           printf("not palindrome\n");
           return 0;
        }
        l++;
        r--;
    }

   printf("palindrome\n");

   exit(0);
}

