#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) do {\
                           a ^= b; \
                           b ^= a; \
                           a ^= b; \
                      } while(0)

#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define SQRT(x) (x)*(x)

#define DEBUG 1

#if DEBUG
#define PRINT_TOKEN(token) do { \
    printf(#token "= %d\n", token); \
    } while(0)
#else
#define PRINT_TOKEN(token)
#endif
        

union un {
    signed char i;
    unsigned char u;
} un;

inline 
int funcMax(int a, int b) 
{
    return ((a) < (b) ? (b) : (a)); 
}

int
main ()
{
    int x = 10;
    int sq;
    union un myUnion;
    myUnion.u = 255;

    PRINT_TOKEN(myUnion.u);
    PRINT_TOKEN(myUnion.i);

#if 0    
    PRINT_TOKEN(x);
    sq = SQRT(9+1);
    PRINT_TOKEN(sq);
    PRINT_TOKEN(x);
#endif    
    int y = 20;
    int z = 30;
    int max=0xbabe;

    PRINT_TOKEN(x);
    PRINT_TOKEN(y);
    PRINT_TOKEN(z);
    if (x < 0)
         SWAP(x, y);
    else
         SWAP(x, z); 

    PRINT_TOKEN(x);
    PRINT_TOKEN(y);
    PRINT_TOKEN(z);
#if 0
    max = funcMax(x++, y++);
    PRINT_TOKEN(max);
    PRINT_TOKEN(x);
    PRINT_TOKEN(y);
    PRINT_TOKEN(z);

    max = MAX(x++, y++);
    PRINT_TOKEN(max);
    PRINT_TOKEN(x);
    PRINT_TOKEN(y);
    PRINT_TOKEN(z);
    
    PRINT_TOKEN(x+y+y);
#endif    
    return 0;
}
