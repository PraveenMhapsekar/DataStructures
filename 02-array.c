/*
 * Given an array of positive integers and a target total of X, find if there exists a contiguous subarray with sum = X 
 *
 * [1, 3, 5, 18]
 * X = 8 Output: True 
 * X = 9 Output: True 
 * X = 10 Output: False 
 * X = 40 Output :False
 */

#include <stdio.h>

#define SIZE 4
#define VERDICT(_X_) printf("X = %3d  Output = %s\n", _X_, (findSubArray(_X_) ? "True" : "False"))

static int A[SIZE] = {1,3,5,18};

int
findSubArray(int X)
{
    int sum;
    int i = 0; // Array iterator
    int j = 0; // SubArray iterator

    for (i = 0; i < SIZE; i++) {
        j = i;
        sum = 0;

        while ((X > sum) && (j < SIZE)) {
            sum = sum + A[j++];
            if (sum == X) {
                return 1;  // Found contiguous sub-array sum = X
            }
        }
    }

    return 0; // contiguous sub-array not found.
}


int
main()
{
    VERDICT(1);
    VERDICT(3);
    VERDICT(4);
    VERDICT(5);
    VERDICT(8);
    VERDICT(18);
    VERDICT(19);
    VERDICT(21);
    VERDICT(22);
    VERDICT(23);
    VERDICT(26);
    VERDICT(27);
    return 0;
}
