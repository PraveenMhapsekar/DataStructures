#include <stdio.h>

#define intNibble ((int)sizeof(int)*2)
#define printFuncName fprintf(stderr, "\n%s()\n", __func__)
void
firstBitSet(int N)
{
    int i;
    int K = N & -N;

    printFuncName;
    for (i = 0; i < (sizeof(int)*8); i++) {
        if (K & (1 << i)) {
               printf("First bit set for 0x%0*x is %d\n", intNibble, N, i);
               printf("RHS cleared bit mask is 0x%0*x\n", intNibble, K -1);
               return;
        }
    } 
}

void bitFlip(int N, int bitNum)
{
    int mask = 1 << bitNum - 1;
    printFuncName;
    printf ("Number for flipping 0x%0*x Bit number to be flipped %d. \nBit flipped number  0x%0*x\n",
             intNibble, N,
             bitNum,
             intNibble, (N ^ mask));
}

int
main (void)
{
    int n = 0xfFFFFF0;
    firstBitSet(n);

    bitFlip(n, 18);
    return 0;
}
