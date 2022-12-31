/* --- Advent of Code 2022 - Day 1: Calorie Counting --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 128
#define MAX_ELVES 1000

/* solution function */
int solution(char part[], char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* solution part-1 */
    if (!strcmp(part, "-p1")) {
        int calories_count = 0;
        int max_calories = 0;

        while (fgets(buffer, MAX_LENGTH, fp)) {
            int value = atoi(buffer);

            /* sum up calories for each elf, compare with max calories and */
            if (value == 0) {
                if (calories_count > max_calories) {
                    max_calories = calories_count;
                }
                /* reset calories count after empty line */
                    calories_count = 0;
            } else {
                calories_count += value;
            }
        }

        printf("%d\n", max_calories);
        return 0;
    }

    /* solution part-2 */
    if (!strcmp(part, "-p2")) {
        int calories_count = 0;
        int elv_count = 1;
        int elv_calories[MAX_ELVES] = {0};

        while(fgets(buffer, MAX_LENGTH, fp)) {
            int value = atoi(buffer);

            if (value == 0) {
                elv_calories[elv_count++] = calories_count;
                calories_count = 0;
            } else {
                calories_count += value;
            }
        }

        /* sort elv_calories using bubble sort */
        for (int i = 0; i < elv_count; i++) {
            for (int j = i+1; j < elv_count; j++) {
                if(elv_calories[i] < elv_calories[j]) {
                    int temp = elv_calories[i];
                    elv_calories[i] = elv_calories[j];
                    elv_calories[j] = temp;
                }
            }
        }

        printf("%d\n", elv_calories[0] + elv_calories[1] + elv_calories[2]);
        return 0;
    }

    return 1;
}

/* main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -p[1|2] <input-file>\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "-p1") || !strcmp(argv[1], "-p2")) {
        solution(argv[1], argv[2]);
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
