#include <stdio.h>

char STRING[] = {"dog and cat bites man and woman"};


void
reverse(char *str)
{
   char *tStr;
   int count = 0;

   if (*str == '\0')  // end of string; Recursion base case
       return;

   tStr = str; // make copy of pointer to traverse string

   while((*tStr != ' ') && (*tStr != '\0')) {
       // traverse till next word or end of the string
       tStr++;
       count++;
   }

   tStr++; // Skip pass ' ' [white space]
   reverse(tStr);    // recursion, repeat same process for rest of the string.

   printf("%.*s ", count, str);

#if 0
   // Another way to print string
   int i = 0;
   while (count) {
       printf("%c", str[i++]);
       count--;
   }

   printf("%c", ' ');
#endif
}


int
main() {
    printf("%s\n", STRING);
    reverse(STRING);
    printf("\n");
    return 0;
}
