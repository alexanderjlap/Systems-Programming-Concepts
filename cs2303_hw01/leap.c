#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if there is an argument passed
    if (argc != 2) {
        printf("Please enter a year as an argument.\n");
        return 1;
    }

    // Get the year from the argument
    int year = atoi(argv[1]);

    // Check if the year is before 1752
    if (year < 1752) {
        printf("This program cannot test the year %d. It only handles the year 1752 and after.\n", year);
        return 1;
    }

    // Check if the year is a leap year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d is a leap year.\n", year);
            } else {
                printf("%d is not a leap year.\n", year);
            }
        } else {
            printf("%d is a leap year.\n", year);
        }
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
