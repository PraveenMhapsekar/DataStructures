#include <stdio.h>

#define N 8

int A1[N] = { 0, 0, 0, 0, -1, 2, 3, 4};
int A2[N] = {-1, 2, 3, 4,  0, 0, 0, 0};
int A3[N] = { 0, 0, 0, 0,  0, 0, 0, 0};
int A4[N] = { 0, 0, -1, 2, 3, 4, 0, 0};
int A5[N] = { 0, 0, 0, 0, -1, 2, 3, 4};
int A6[N] = { -1, -2, -3, -4, -5, -6, -7, -9};
int A7[N] = { -1, -2, -3, -4, -5, -6, -7, 0};
int A8[N] = { -1, -2, -3, 0, -5, -6, -7, 0};
int A9[N] = { 0, 0, 0, 0,  0, 0, 0, -1};

int
getNonZeroNum(int *A)
{
    int start;
    int end;
    int cnt;

    cnt   = 0;
    start = 0;
    end   = N - 1;

    while (end >= start) {
        if (!A[start]) {
            A[start] = A[end];
            end--;
            cnt++;
        } else {
            start++;
        }
    }

    return N - cnt;
}

int
main(void)
{
    printf("nonzero elemnets %d\n", 4 == getNonZeroNum(&A1[0]) ? 4 : -1);
    printf("nonzero elemnets %d\n", 4 == getNonZeroNum(&A2[0]) ? 4 : -1);
    printf("nonzero elemnets %d\n", 0 == getNonZeroNum(&A3[0]) ? 0 : -1);
    printf("nonzero elemnets %d\n", 4 == getNonZeroNum(&A4[0]) ? 4 : -1);
    printf("nonzero elemnets %d\n", 4 == getNonZeroNum(&A5[0]) ? 4 : -1);
    printf("nonzero elemnets %d\n", 8 == getNonZeroNum(&A6[0]) ? 8 : -1);
    printf("nonzero elemnets %d\n", 7 == getNonZeroNum(&A7[0]) ? 7 : -1);
    printf("nonzero elemnets %d\n", 6 == getNonZeroNum(&A8[0]) ? 6 : -1);
    printf("nonzero elemnets %d\n", 1 == getNonZeroNum(&A9[0]) ? 1 : -1);
    return 0;
}



