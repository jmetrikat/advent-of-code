/* --- Advent of Code 2022 - Day 2: Rock Paper Scissor --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int final_score = 0;

        while (fgets(buffer, MAX_LENGTH - 1, fp)) {
            /* check the format */
            if (strlen(buffer) < 3) {
                fprintf(stderr, "Incorrect format in line \'%s\'\n", buffer);
                return 1;
            }

            /* check for invalid moves */
            if ((buffer[0] != 'A' && buffer[0] != 'B' && buffer[0] != 'C') || (buffer[2] != 'X' && buffer[2] != 'Y' && buffer[2] != 'Z')) {
                fprintf(stderr, "Incorrect format: \'%c %c\' Moves should be A, B or C and X, Y or Z\n", buffer[0], buffer[2]);
                return 1;
            }

            /* map the moves to values */
            int me = buffer[2] - 'X';
            int opp = buffer[0] - 'A';

            /* calculate the score */
            int score = (me == opp) ? 3 : ((me == 0 && opp == 2) || (me == 2 && opp == 1) || (me == 1 && opp == 0)) ? 6 : 0;
            int shape_score = me + 1;
            final_score += (score + shape_score);
        }

        printf("%d\n", final_score);

    /* file not found */
    } else {
        fprintf(stderr, "Problems opening file '%s'\n", input_file);
        exit(1);
    }

    return 0;
}

int part_2(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int final_score = 0;

        while (fgets(buffer, MAX_LENGTH - 1, fp)) {
            /* check the format */
            if (strlen(buffer) < 3) {
                fprintf(stderr, "Incorrect format in line \'%s\'\n", buffer);
                return 1;
            }

            /* check for invalid moves */
            if ((buffer[0] != 'A' && buffer[0] != 'B' && buffer[0] != 'C') || (buffer[2] != 'X' && buffer[2] != 'Y' && buffer[2] != 'Z')) {
                fprintf(stderr, "Incorrect format: \'%c %c\' Moves should be A, B or C and X, Y or Z\n", buffer[0], buffer[2]);
                return 1;
            }

            /* map the moves to values */
            int opp = buffer[0] - 'A';
            int outcome = buffer[2] - 'X';
            int me;

            /* figure out what shape to choose */
            switch (outcome) {
                case 0:
                    me = (opp == 0) ? 2 : (opp == 1) ? 0
                                                        : 1;
                    break;
                case 1:
                    me = opp;
                    break;
                case 2:
                    me = (opp == 0) ? 1 : (opp == 1) ? 2
                                                        : 0;
                    break;
            }

            int score = outcome * 3;
            int shape_score = me + 1;
            final_score += (score + shape_score);
        }

        printf("%d\n", final_score);

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
