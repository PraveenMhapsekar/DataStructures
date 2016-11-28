#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int column[20];
int cnt;

void 
print(int n)
{
    int i, j;

    printf("%1d-Queen Solution #%02d:\n", n, cnt++);
    printf("%c ", '*');

    for (i = 0; i < n; i++) {
        printf("%d ",i);
    }

    for (i = 0; i < n; i++) {
        printf("\n%d ",i);
        for (j = 0; j < n; j++) {
            if (column[i] == j) {
                printf("Q "); 
            } else {
                printf(". "); 
            }
        }
    }

    printf("\n\n");
}

int 
validate(int r, int c)
{
    int i;

    for (i = 0; i < r; i++) {
        if (column[i] == c) {
            return 0;
        } else {
            if (abs(column[i] - c) == abs(i - r)) {
                return 0;
            }
        }
    }

    return 1; 
}

void 
placeQueen(int r, int n)
{
    int col;

    for (col = 0; col < n; col++) {
        if (validate(r, col)) {
            column[r] = col; 
            if (r == n - 1) {
                print(n); 
                exit(0); /* Commenting out exit will print all solutions */
            } else {            
                placeQueen(r + 1, n);
            }
        }
    }
}

int 
main()
{
    placeQueen(0, 8);
    return 0;
}
