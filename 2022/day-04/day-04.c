/* --- Advent of Code 2023 - Day 4: Camp Cleanup --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int fully_contained = 0;

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            int a1, a2, b1, b2;

            /* check format and parse the numbers */
            if (sscanf(buffer, "%d-%d,%d-%d", &a1, &a2, &b1, &b2) != 4) {
                fprintf(stderr, "Incorrect format in line '%.*s'\n", (int) strlen(buffer) - 1, buffer);
                exit(1);
            }

            /* check if section assinments pairs fully contain each other */
            if ((a1 <= b1 && a2 >= b2) || (b1 <= a1 && b2 >= a2)) {
                fully_contained++;
            }
        }

        printf("%d\n", fully_contained);

    /* file not found */
    } else {
        fprintf(stderr, "Problems opening file '%s'\n", input_file);
        exit(1);
    }

    return 0;
}

/* solution part-2 */
int part_2(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int overlapping = 0;

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            int a1, a2, b1, b2;

            /* check format and parse the numbers */
            if (sscanf(buffer, "%d-%d,%d-%d", &a1, &a2, &b1, &b2) != 4) {
                fprintf(stderr, "Incorrect format in line '%.*s'\n", (int) strlen(buffer) - 1, buffer);
                exit(1);
            }

            /* check if section assinments overlap */
            if (!(a2 < b1 || b2 < a1)) {
                overlapping++;
            }
        }

        printf("%d\n", overlapping);

    /* file not found */
    } else {
        fprintf(stderr, "Problems opening file '%s'\n", input_file);
        exit(1);
    }

    return 0;
}

/* main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -p[1|2] <input-file>\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "-p1")) {
        part_1(argv[2]);
    } else if (!strcmp(argv[1], "-p2")) {
        part_2(argv[2]);
    } else {
        fprintf(stderr, "Invalid argument: '%s'\n", argv[1]);
        return 1;
    }

    return 0;
}
