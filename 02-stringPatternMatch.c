#include <stdio.h>
#include <string.h>

/* Horowitz Sahani page 93 */
int 
nfind(char *string, char *pat)
{
    int i, j;
    int lastp;
    int lasts;
    int start = 0;
    int end;

    lastp = strlen(pat) - 1;
    lasts = strlen(string) - 1;
    end = lastp;

    for (i = 0; end <= lasts;) {
        if (string[end] == pat[lastp]) {
            for(j = 0, i = start; j < lastp; ) {
                if(pat[j] == string[i]) {
                    j++;
                    i++;
                } else {
                    break;
                }
            }
            if (j == lastp)
                return start;
        }
        start++;
        end++;
    }
    return -1;
}


int
main(void)
{
    char *string = {"ababbaabaa"};
    char *pat    = {"aab"};

    return (printf("\"%s\" %s in \"%s\"\n", 
           pat,
           (nfind(string, pat) == -1) ? "not found" : "found",
           string));

}

