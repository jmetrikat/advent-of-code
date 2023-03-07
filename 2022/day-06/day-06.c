/* --- Advent of Code 2023 - Day 6: Tuning Trouble --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        /* read data stream */
        if (!fgets(buffer, MAX_LENGTH - 1, fp)) {
            fprintf(stderr, "Empty file '%s'\n", input_file);
            exit(1);
        }

        /* detect start-of-packet marker by comparing 4 consecutive characters */
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] != buffer[i + 1] && buffer[i] != buffer[i + 2] && buffer[i] != buffer[i + 3] &&
                buffer[i + 1] != buffer[i + 2] && buffer[i + 1] != buffer[i + 3] &&
                buffer[i + 2] != buffer[i + 3]) {
                /* print marker position */
                printf("%d\n", i + 4);
                break;
            }
        }

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
        /* read data stream */
        if (!fgets(buffer, MAX_LENGTH - 1, fp)) {
            fprintf(stderr, "Empty file '%s'\n", input_file);
            exit(1);
        }

        int MARKER_SIZE = 14;

        /* detect start-of-packet marker by comparing 14 consecutive characters */
        for (int i = 0; i < (strlen(buffer) - MARKER_SIZE); i++) {
            int is_marker = 1;

            for (int j = 0; j < MARKER_SIZE; j++) {
                for (int k = j + 1; k < MARKER_SIZE; k++) {
                    if (buffer[i + j] == buffer[i + k]) {
                        is_marker = 0;

                        /* use 'goto' to increase performance by skipping further comparisons */
                        goto check;
                    }
                }
            }

        /* check flag and print marker position */
        check:
            if (is_marker) {
                printf("%d\n", i + MARKER_SIZE);
                break;
            }
        }

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
