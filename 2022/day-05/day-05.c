/* --- Advent of Code 2023 - Day 5: Supply Stack --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_STACKS 32
#define MAX_HEIGHT 32

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* store stacks in 2d array and keep track of their height */
    int no_stacks = 0;
    int stacks[MAX_STACKS][MAX_HEIGHT];
    int stack_height[MAX_STACKS];
    for (int i = 0; i <= MAX_STACKS; i++) stack_height[i] = 0;

    /* file opened successfully */
    if (fp != NULL) {

        /* create stacks */
        while (fgets(buffer, MAX_LENGTH, fp) && buffer [1] != '1') {
            no_stacks = strlen(buffer) / 4;

            /* fill stacks with crates */
            for (int i = 0; i < no_stacks; i++) {
                if (buffer[i * 4] == '[') {
                    stacks[i + 1][stack_height[i + 1]++] = buffer[i * 4 + 1];
                }
            }
        }

        /* reverse stacks */
        for (int i = 1; i <= no_stacks; i++) {
            for (int j = 0; j < stack_height[i] / 2; j++) {
                char tmp = stacks[i][j];
                stacks[i][j] = stacks[i][stack_height[i] - j - 1];
                stacks[i][stack_height[i] - j - 1] = tmp;
            }
        }

        /* skip empty line */
        fgets(buffer, MAX_LENGTH, fp);

        /* move one crate at a time */
        while (fgets(buffer, MAX_LENGTH, fp)) {
            int crates_to_move, dest, src;
            if (sscanf(buffer, "move %d from %d to %d", &crates_to_move, &src, &dest) != 3) {
                fprintf(stderr, "Error parsing line '%.*s'\n", (int) strlen(buffer), buffer);
                exit(1);
            }

            for (int i = 0; i < crates_to_move; i++) {
                stacks[dest][stack_height[dest]++] = stacks[src][--stack_height[src]];
            }
        }

        /* print crates at the top of each stack */
        for (int i = 1; i <= no_stacks; i++) {
            printf("%c", stacks[i][stack_height[i] - 1]);
        }
        printf("\n");

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

    /* store stacks in 2d array and keep track of their height */
    int no_stacks = 0;
    int stacks[MAX_STACKS][MAX_HEIGHT];
    int stack_height[MAX_STACKS];
    for (int i = 0; i <= MAX_STACKS; i++) stack_height[i] = 0;

    /* file opened successfully */
    if (fp != NULL) {
        /* create stacks */
        while (fgets(buffer, MAX_LENGTH, fp) && buffer[1] != '1') {
            no_stacks = strlen(buffer) / 4;

            /* fill stacks with crates */
            for (int i = 0; i < no_stacks; i++) {
                if (buffer[i * 4] == '[') {
                    stacks[i + 1][stack_height[i + 1]++] = buffer[i * 4 + 1];
                }
            }
        }

        /* reverse stacks */
        for (int i = 1; i <= no_stacks; i++) {
            for (int j = 0; j < stack_height[i] / 2; j++) {
                char tmp = stacks[i][j];
                stacks[i][j] = stacks[i][stack_height[i] - j - 1];
                stacks[i][stack_height[i] - j - 1] = tmp;
            }
        }

        /* skip empty line */
        fgets(buffer, MAX_LENGTH, fp);

        /* move crates at once */
        while (fgets(buffer, MAX_LENGTH, fp)) {
            int crates_to_move, dest, src;
            sscanf(buffer, "move %d from %d to %d", &crates_to_move, &src, &dest);

            for (int i = 0; i < crates_to_move; i++) {
                stacks[dest][stack_height[dest]++] = stacks[src][stack_height[src] - crates_to_move + i];
            }
            stack_height[src] -= crates_to_move;
        }

        /* print crates at the top of each stack */
        for (int i = 1; i <= no_stacks; i++) {
            printf("%c", stacks[i][stack_height[i] - 1]);
        }
        printf("\n");

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
