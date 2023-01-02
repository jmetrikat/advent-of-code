/* --- Advent of Code 2022 - Day 3: Rucksack Reorganization --- */

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
        int score = 0;
        char duplicate;

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            /* trim trailing whitespaces */
            int i;
            for (i = strlen(buffer) - 1; i >= 0; i--) {
                if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\r' && buffer[i] != '\n'){
                    break;
                }
            }
            buffer[i+1] = '\0';

            /* check the format */
            if (strlen(buffer) % 2 != 0) {
                fprintf(stderr, "Incorrect format in line '%s' \n", buffer);
                exit (1);
            }

            /* find the common item */
            int found_duplicate = 0;
            for (int i = 0; i < strlen(buffer) / 2; i++) {
                for (int j = strlen(buffer) / 2; j < strlen(buffer); j++) {
                    if (buffer[i] == buffer[j]){
                        duplicate = buffer[i];
                        found_duplicate = 1;

                        /* calculate the items priority */
                        score += (duplicate >= 'A' && duplicate <= 'Z') ? (duplicate - 'A' + 27) : (duplicate - 'a' + 1);
                        break;
                    }
                }
                /* duplicate found, so continue with the next compartment */
                if (found_duplicate) { break; }
             }
        }

        printf("%d\n", score);

    /* file not found */
    } else {
        fprintf(stderr,"Problems opening file '%s'\n", input_file);
        exit (1);
    }

    return 0;
}

/* solution part-2 */
int part_2(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[3][MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int score = 0;
        char duplicate;

        while (fgets(buffer[0], MAX_LENGTH - 1, fp) != NULL) {
            /* read the next two lines for the block-of-three */
            if (fgets(buffer[1], MAX_LENGTH - 1, fp) == 0 || fgets(buffer[2], MAX_LENGTH - 1, fp) == 0) {
                fprintf(stderr, "Incorrect format: Number of rucksacks must be a multiple of three.\n");
                exit (1);
            }

            /* groups of three */
            for (int k = 0; k < 3; k++) {
                /* trim trailing whitespaces */
                int i;
                for (i = strlen(buffer[k]) - 1; i >= 0; i--) {
                    if (buffer[k][i] != ' ' && buffer[k][i] != '\t' && buffer[k][i] != '\r' && buffer[k][i] != '\n') {
                        break;
                    }
                }
                buffer[k][i + 1] = '\0';

                /* check the format */
                if (strlen(buffer[k]) % 2 != 0) {
                    fprintf(stderr, "Incorrect format in line '%s' \n", buffer[k]);
                    exit (1);
                }
            }

            /* find the common item */
            int found_duplicate = 0;
            for (int i = 0; i < strlen(buffer[0]); i++) {
                for (int j = 0; j < strlen(buffer[1]); j++) {
                    for (int l = 0; l < strlen(buffer[2]); l++) {
                        if (buffer[0][i] == buffer[1][j] && buffer[1][j] == buffer[2][l]) {
                            duplicate = buffer[0][i];
                            found_duplicate = 1;

                            /* calculate the items priority */
                            score += (duplicate >= 'A' && duplicate <= 'Z') ? (duplicate - 'A' + 27) : (duplicate - 'a' + 1);
                            break;
                        }
                    }
                    /* duplicate found, so continue with the next compartment */
                    if (found_duplicate) { break; }
                }
                /* duplicate found, so continue with the next compartment */
                if (found_duplicate) { break; }
            }
        }

        printf("%d\n", score);

        /* file not found */
    } else {
        fprintf(stderr,"Problems opening file '%s'\n", input_file);
        exit (1);
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
    }else if (!strcmp(argv[1], "-p2")) {
        part_2(argv[2]);
    } else {
        fprintf(stderr, "Invalid argument: '%s'\n", argv[1]);
        return 1;
    }

    return 0;
}
