#include <stdio.h>
#include <stdlib.h>

enum boolean { FALSE, TRUE };
typedef enum boolean bool;

typedef enum { ONE, TWO } nums;

int main(int argc, char **argv) {
    bool flag = TRUE;

    if (flag == TRUE) {
        printf("\nFlag %d", flag);
        flag = FALSE;
    }

    if (!flag) {
        printf("\nFlag %d", flag);
    }

    enum week { SUN, MON, TUE, WED, THU, FRI, SAT };
    enum week weekdays[] = { MON, TUE, WED, THU, FRI };
    enum week weekends[] = { SAT, SUN };

    printf("\nsize of enum week: %lu", sizeof(enum week));

    int len_weekdays = sizeof(weekdays) / sizeof(weekdays[0]);
    printf("\nweekdays: %d", len_weekdays);

    int len_weekends = sizeof(weekends) / sizeof(weekends[0]);
    printf("\nweekends: %d", len_weekends);

    enum week selected_day = WED;
    switch (selected_day) {
        case MON: printf("\nMonday"); break;
        case TUE: printf("\nTuesday"); break;
        case WED: printf("\nWednesday"); break;
        case THU: printf("\nThursday"); break;
        case FRI: printf("\nFriday"); break;
        case SAT: printf("\nSaturday"); break;
        case SUN: printf("\nSunday"); break;
    }

    enum vowels { a = 'a', e = 'e' , i = 'i', o = 'o', u = 'u' };
    printf("\nsize of enum vowels: %lu", sizeof(enum vowels));
    printf("\n%c, %c, %c, %c, %c", a, e, i, o, u);

    // non-default index
    typedef enum { RED = 1, GREEN = 2, BLUE = 3 } rgb;
    rgb color = RED;
    printf("\nRGB color: %d", color);

    printf("\n");
    return EXIT_SUCCESS;
}

