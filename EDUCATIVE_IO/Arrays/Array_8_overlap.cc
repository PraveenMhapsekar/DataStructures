/*
	You are given an array (list) of interval pairs as input where each interval has a start and end timestamp. 
  The input array is sorted by starting timestamps. 
  You are required to merge overlapping intervals and return a new output array.

	Consider the input array below. 
  Intervals (1, 5), (3, 7), (4, 6), (6, 8) are overlapping so they should be merged to one big interval (1, 8). 
  Similarly, intervals (10, 12) and (12, 15) are also overlapping and should be merged to (10, 15).
*/

#include <stdio.h>

typedef struct point {
  int x;  // DONOT confuse x, y with graph coordinates, its just linear start end values
  int y;
} point_t;

int max(int x, int y) {
  if (x > y ) return x;
  return y;
}

int min(int x, int y) {
  if (x < y ) return x;
  return y;
}

point_t overlap[100];

int overlapFunc(point_t *PA, int size) {
  int k = 0;
  point_t res;
  res.x = PA[0].x;
  res.y = PA[0].y;
	for (int i = 1; i < size; i++) {
    point_t pt;
    pt.x = PA[i].x;
    pt.y = PA[i].y;
  
    if (pt.x <= res.y) {
      res.y = max(res.y, pt.y);
      res.x = min(res.x, pt.x);
    } else {
      // no overlap
      overlap[k].x = res.x;
      overlap[k].y = res.y;
      k++;
      res.x = pt.x;
      res.y = pt.y;
    }
	}

  // return last result
	overlap[k].x = res.x;
	overlap[k].y = res.y;
  k++;
  return k;
}

int
main () {
   int i = 0;
   point_t input[10];
   input[i].x = 1;
   input[i].y = 5;
   i++;

   input[i].x = 3;
   input[i].y = 2;
   i++;

   input[i].x = 4;
   input[i].y = 6;
   i++;

   input[i].x = 6;
   input[i].y = 8;
   i++;

   input[i].x = 10;
   input[i].y = 12;
   i++;

   input[i].x = 11;
   input[i].y = 15;
   i++;

   int k = overlapFunc(input, i);
   for (int j = 0; j < k; j++) {
     printf("%d : x=%2d y=%2d\n", j, overlap[j].x, overlap[j].y);
   }

   return 0;
}
