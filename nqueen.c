#include<stdio.h>
#include <stdlib.h>
#include<math.h>
 
int column[20];
int cnt;

void 
print(int n)
{
    int i,j;
    printf("Solution %d:\n", cnt++);

    printf("%c ", '*');
    for (i = 0; i < n; ++i) {
        printf("%d ",i);
    }

    for (i = 0; i < n; ++i) {
        printf("\n%d ",i);
        for(j = 0; j < n; ++j) {
            if(column[i] == j)
                printf("Q "); 
            else
                printf(". "); 
        }
    }
    printf("\n\n");
}

int 
validate(int R, int C)
{
    int i;

    for (i = 0; i < R; i++) {
        if (column[i] == C) {
            return 0;
        } else {
            if (abs(column[i] - C) == abs(i - R)) {
                return 0;
            }
        }
    }

    return 1; 
}

void 
placeQueen(int R, int n)
{
    int col;
    for (col = 0; col < n; col++) {
        if (validate(R, col)) {
            column[R] = col; 
            if (R == n - 1) {
                print(n); 
                exit(0); /* Commenting out exit will print all solutions */
            } else {            
                placeQueen(R + 1, n);
            }
        }
    }
}

int 
main()
{
    int n, i, j;

//    printf(" - N Queens Problem Using Backtracking -");
//    printf("\n\nEnter number of Queens:");
//    scanf("%d",&n);
    n = 8;
    placeQueen(1, n);
    return 0;
}
