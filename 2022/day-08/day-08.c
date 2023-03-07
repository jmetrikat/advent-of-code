/* --- Advent of Code 2023 - Day 8: Treetop Tree House --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

/* solution part-1 */
static int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        /* read and check first line */
        if (!fgets(buffer, MAX_LENGTH - 1, fp)) {
            fprintf(stderr, "Could not read file '%s'\n", input_file);
            exit(1);
        }

        /* initialize array for map */
        int width = strlen(buffer) - 1;
        int height = width;
        char **map = (char **)malloc(sizeof(char *) * height);

        /* read map line by line */
        for (int i = 0; i < height; i++) {
            map[i] = (char *)malloc(sizeof(char) * width);
            for (int j = 0; j < width; j++) {
                map[i][j] = buffer[j];
            }
            /* get the next line and check format */
            if (!fgets(buffer, MAX_LENGTH - 1, fp) && (i < height - 1)) {
                fprintf(stderr, "Format error: height does not equal width: %d\n", i);
                exit(1);
            }
        }

        /* count visible trees */
        int visible_cnt = 0;
        int hidden = 0;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                /* check if tree is visible to north */
                hidden = 0;
                for (int k = 0; k <= i - 1; k++) {
                    if (map[k][j] >= map[i][j]) {
                        hidden = 1;
                        break;
                    }
                }
                if (!hidden) {
                    visible_cnt += 1;
                    continue;
                }

                /* check if tree is visible to south */
                hidden = 0;
                for (int k = i + 1; k < height; k++) {
                    if (map[k][j] >= map[i][j]) {
                        hidden = 1;
                        break;
                    }
                }
                if (!hidden) {
                    visible_cnt += 1;
                    continue;
                }

                /* check if tree is visible to west */
                hidden = 0;
                for (int k = 0; k <= j - 1; k++) {
                    if (map[i][k] >= map[i][j]) {
                        hidden = 1;
                        break;
                    }
                }
                if (!hidden) {
                    visible_cnt += 1;
                    continue;
                }

                /* check if tree is visible to east */
                hidden = 0;
                for (int k = j + 1; k < width; k++) {
                    if (map[i][k] >= map[i][j]) {
                        hidden = 1;
                        break;
                    }
                }
                if (!hidden) {
                    visible_cnt += 1;
                    continue;
                }
            }
        }

        printf("%d\n", visible_cnt);

        /* free allocated memory */
        for (int i = 0; i < width; i++)
            free(map[i]);
        free(map);

    /* file not found */
    } else {
        fprintf(stderr, "Problems opening file '%s'\n", input_file);
        exit(1);
    }

    return 0;
}

/* solution part-2 */
static int part_2(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        // TODO

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
