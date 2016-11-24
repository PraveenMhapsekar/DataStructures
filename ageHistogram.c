#include <stdio.h>

#define N 5
#define STRT_YEAR 1900
#define LAST_YEAR 2000
#define MAXYEARS (LAST_YEAR - STRT_YEAR) + 1

int year[MAXYEARS];
int maxYear = 0;

typedef struct birth_rec {
    int birth;
    int death;
} birth_rec_t;

birth_rec_t birthRecord[N] = {{1920, 1967}, {1921, 1970}, {1922, 1987}, {1928, 2000}, {1989, 1990}};

void
create_histogram(int birth, int death)
{
    int i;
    birth -= STRT_YEAR;
    death -= STRT_YEAR;

    for (i = birth; i <= death; i++) {
        year[i]++;
        if (year[i] > year[maxYear]) {
            maxYear = i;
        }
    }
}

int 
main(void) 
{
    int i = 0;

    for (i = 0; i < N; i++) {
        printf("Person %d, birth %d death %d\n", i, birthRecord[i].birth, birthRecord[i].death);
        create_histogram(birthRecord[i].birth, birthRecord[i].death);
    }

    printf("Year with maximun number people living is %d, that year %d people were alive\n", maxYear + STRT_YEAR, year[maxYear]);
}
