/* --- Advent of Code 2023 - Day 9: Rope Bridge --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_POS 6000
#define NO_KNOTS 10

static int tail_pos_visited[MAX_POS][2];
static int tail_pos_visited_count = 0;

/* add position to tail_pos_visited */
void add_pos(int *pos) {
    int pos_found = 0;
    for (int i = 0; i < tail_pos_visited_count; i++) {
        if (tail_pos_visited[i][0] == pos[0] && tail_pos_visited[i][1] == pos[1]) {
            pos_found = 1;
            break;
        }
    }

    if (!pos_found) {
        if (tail_pos_visited_count >= MAX_POS) {
            fprintf(stderr, "Buffer too small: %d\n", MAX_POS);
            exit(1);
        }

        tail_pos_visited[tail_pos_visited_count][0] = pos[0];
        tail_pos_visited[tail_pos_visited_count][1] = pos[1];
        tail_pos_visited_count++;
    }

    return;
}


/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        /* initialize head and tail */
        int head [] = {0, 0};
        int tail [] = {0, 0};
        add_pos(tail);

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            char direction = buffer[0];
            char steps = atoi(&(buffer[2]));

            /* grid mapping of directions */
            for (int i = 0; i < steps; i++) {
                switch (direction) {
                    case 'R':
                        head[0] += 1;
                        break;
                    case 'L':
                        head[0] -= 1;
                        break;
                    case 'U':
                        head[1] += 1;
                        break;
                    case 'D':
                        head[1] -= 1;
                        break;
                    default:
                        fprintf(stderr, "Invalid direction: '%c'\n", direction);
                        exit(1);
                }

                int diff_x = head[0] - tail[0];
                int diff_y = head[1] - tail[1];

                /* check if tail is touching head ... */
                if (abs(diff_x) <= 1 && abs(diff_y) <= 1) {
                    continue;

                /* ... otherwise adjust the tail with simple imlementation of signum function */
                } else {
                    tail[0] += (diff_x > 0) - (diff_x < 0);
                    tail[1] += (diff_y > 0) - (diff_y < 0);
                    add_pos(tail);
                }
            }
        }

        printf("%d\n", tail_pos_visited_count);

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
        /* initialize head and tail */
        int knots[NO_KNOTS][2];
        for (int i = 0; i < NO_KNOTS; i++) {
            knots[i][0] = 0;
            knots[i][1] = 0;
        }
        add_pos(knots[9]);

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            char direction = buffer[0];
            char steps = atoi(&(buffer[2]));

            /* grid mapping of directions */
            for (int i = 0; i < steps; i++) {
                switch (direction) {
                    case 'R':
                        knots[0][0] += 1;
                        break;
                    case 'L':
                        knots[0][0] -= 1;
                        break;
                    case 'U':
                        knots[0][1] += 1;
                        break;
                    case 'D':
                        knots[0][1] -= 1;
                        break;
                    default:
                        fprintf(stderr, "Invalid direction: '%c'\n", direction);
                        exit(1);
                }

                for (int i = 0; i < NO_KNOTS - 1; i++) {
                    int diff_x = knots[i][0] - knots[i + 1][0];
                    int diff_y = knots[i][1] - knots[i + 1][1];

                    /* check if tail is touching head ... */
                    if (abs(diff_x) <= 1 && abs(diff_y) <= 1) {
                        continue;

                    /* ... otherwise adjust the tail with simple imlementation of signum function */
                    } else {
                        knots[i + 1][0] += (diff_x > 0) - (diff_x < 0);
                        knots[i + 1][1] += (diff_y > 0) - (diff_y < 0);
                    }
                }
                add_pos(knots[9]);
            }
        }

        printf("%d\n", tail_pos_visited_count);

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
