/* --- Advent of Code 2023 - Day 17: Pyroclastic Flow --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 16000

/* keep track of all occupied locations */
int locations[MAX_LENGTH][2];
int rock_counter = 0;
int locations_counter = 0;

/* rock structure */
typedef struct rock {
    int no_elements;
    int elements[5][2];
} rockT;

/* get  the initial coordinates of the five different rock types */
struct rock *generate_rock(int rock_type, int y) {
    rockT *rock = malloc(sizeof(rockT));

    switch (rock_type) {
        case 0: /* flat */
            rock->no_elements = 4;
            rock->elements[0][0] = 2, rock->elements[0][1] = y;
            rock->elements[1][0] = 3, rock->elements[1][1] = y;
            rock->elements[2][0] = 4, rock->elements[2][1] = y;
            rock->elements[3][0] = 5, rock->elements[3][1] = y;
            break;
        case 1: /* cross */
            rock->no_elements = 5;
            rock->elements[0][0] = 2, rock->elements[0][1] = y + 1;
            rock->elements[1][0] = 3, rock->elements[1][1] = y;
            rock->elements[2][0] = 3, rock->elements[2][1] = y + 1;
            rock->elements[3][0] = 3, rock->elements[3][1] = y + 2;
            rock->elements[4][0] = 4, rock->elements[4][1] = y + 1;
            break;
        case 2: /* inverted L */
            rock->no_elements = 5;
            rock->elements[0][0] = 2, rock->elements[0][1] = y;
            rock->elements[1][0] = 3, rock->elements[1][1] = y;
            rock->elements[2][0] = 4, rock->elements[2][1] = y;
            rock->elements[3][0] = 4, rock->elements[3][1] = y + 1;
            rock->elements[4][0] = 4, rock->elements[4][1] = y + 2;
            break;
        case 3: /* vertical */
            rock->no_elements = 4;
            rock->elements[0][0] = 2, rock->elements[0][1] = y;
            rock->elements[1][0] = 2, rock->elements[1][1] = y + 1;
            rock->elements[2][0] = 2, rock->elements[2][1] = y + 2;
            rock->elements[3][0] = 2, rock->elements[3][1] = y + 3;
            break;
        case 4: /* square */
            rock->no_elements = 4;
            rock->elements[0][0] = 2, rock->elements[0][1] = y;
            rock->elements[1][0] = 2, rock->elements[1][1] = y + 1;
            rock->elements[2][0] = 3, rock->elements[2][1] = y;
            rock->elements[3][0] = 3, rock->elements[3][1] = y + 1;
            break;
        default:
            fprintf(stderr, "Invalid rock type: '%d'\n", rock_type);
            exit(1);
    }

    return rock;
}

/* check if rock can be moved in a given direction */
int moveable(rockT *rock, char direction) {
    extern int locations[MAX_LENGTH][2];
    extern int locations_counter;

    if (direction == '<') {
        for (int i = 0; i < rock->no_elements; i++) {
            for (int j = 0; j <= locations_counter; j++) {
                if (rock->elements[i][0] - 1 == locations[j][0] &&
                    rock->elements[i][1] == locations[j][1]) {
                    return 0;
                }
            }
        }
    } else if (direction == '>') {
        for (int i = 0; i < rock->no_elements; i++) {
            for (int j = 0; j <= locations_counter; j++) {
                if (rock->elements[i][0] + 1 == locations[j][0] &&
                    rock->elements[i][1] == locations[j][1]) {
                    return 0;
                }
            }
        }
    } else {
        fprintf(stderr, "Invalid direction: '%c'\n", direction);
        exit(1);
    }

    return 1;
}

/* move rock according to jet direction */
rockT *move(rockT *rock, char dir) {
    /* move left if rock is still in bounds */
    if (dir == '<' && rock->elements[0][0] > 0) {
        for (int i = 0; i < rock->no_elements; i++) {
            rock->elements[i][0] -= 1;
        }

    /* move right if rock is still in bounds */
    } else if (dir == '>' && rock->elements[rock->no_elements - 1][0] < 6) {
        for (int i = 0; i < rock->no_elements; i++) {
            rock->elements[i][0] += 1;
        }

    /* return original rock if no movement is possible */
    } else if (dir == '<' || dir == '>') {
        return rock;

    } else {
        fprintf(stderr, "Invalid direction: '%c'\n", dir);
        exit(1);
    }

    return rock;
}

/* check if rock can be dropped one step */
int dropable(rockT *rock) {
    extern int locations[MAX_LENGTH][2];
    extern int locations_counter;

    /* check if rock is at the bottom */
    for (int i = 0; i < rock->no_elements; i++) {
        for (int j = 0; j <= locations_counter; j++) {
            if (rock->elements[i][0] == locations[j][0] &&
                rock->elements[i][1] - 1 == locations[j][1]) {
                return 0;
            }
        }
    }

    return 1;
}

/* drop rock one step */
rockT *drop(rockT *rock) {
    for (int i = 0; i < rock->no_elements; i++) {
        rock->elements[i][1] -= 1;
    }

    return rock;
}

void print_locations(int max_y, int max_x, rockT *rock, int settled) {
    extern int locations[MAX_LENGTH][2];
    extern int locations_counter;

    for (int i = max_y + 4; i >= 0; i--) {
        for (int j = 0; j < max_x; j++) {
            int found = 0;

            /* check if location is part of rock */
            if (!settled) {
                for (int k = 0; k < rock->no_elements; k++) {
                    if (rock->elements[k][0] == j && rock->elements[k][1] == i) {
                        printf("@");
                        found = 1;
                        break;
                    }
                }
            }

            /* check if location is part of settled rocks */
            for (int k = 0; k <= locations_counter; k++) {
                if (locations[k][0] == j && locations[k][1] == i) {
                    printf("#");
                    found = 1;
                    break;
                }
            }

            /* print empty space if location is not part of rock or settled rocks */
            if (!found) {
                printf(".");
            }
        }

        printf("\n");
    }

    printf("\n");
}

/* drop rocks until max_iterations is reached */
int drop_rocks(char *direction, long max_iterations) {
    extern int locations_counter;
    int direction_counter = 0;
    int max_y = 0;

    rockT *rock = malloc(sizeof(rockT));
    rock = generate_rock(rock_counter % 5, max_y + 4);

    while (1) {
        char dir = direction[direction_counter];

        if (moveable(rock, dir)) {
            rock = move(rock, dir);
        }

        if (dropable(rock)) {
            rock = drop(rock);
        } else {
            /* add locations of settled rock to locations */
            for (int i = 0; i < rock->no_elements; i++, locations_counter++) {
                locations[locations_counter][0] = rock->elements[i][0];
                locations[locations_counter][1] = rock->elements[i][1];
            }

            /* adjust max_y to give next rock enough space */
            int max_rock_y = 0;
            for (int i = 0; i < rock->no_elements; i++) {
                max_rock_y = rock->elements[i][1] > max_rock_y ? rock->elements[i][1] : max_rock_y;
            }
            max_y = max_rock_y > max_y ? max_rock_y : max_y;


            /* check if max_iterations is reached, otherwise generate new rock */
            if ((rock_counter + 1) == max_iterations) {
                return max_y;
            } else {
                rock_counter += 1;
                rock = generate_rock(rock_counter % 5, max_y + 4);
            }
        }

        direction_counter = direction_counter > strlen(direction) - 3 ? 0 : direction_counter + 1;
    }

    return -1;
}

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    extern int locations[MAX_LENGTH][2];
    extern int locations_counter;

    /* file opened successfully */
    if (fp != NULL) {
        if (fgets(buffer, MAX_LENGTH, fp) == NULL) {
            fprintf(stderr, "Problems reading file '%s'\n", input_file);
            exit(1);
        }

        /* add floor to locations */
        for (locations_counter = 0; locations_counter < 8; locations_counter++) {
            locations[locations_counter][0] = locations_counter;
            locations[locations_counter][1] = 0;
        }

        printf("%d\n", drop_rocks(buffer, 2022));

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

    extern int locations[MAX_LENGTH][2];
    extern int locations_counter;

    /* file opened successfully */
    if (fp != NULL) {
        if (fgets(buffer, MAX_LENGTH, fp) == NULL) {
            fprintf(stderr, "Problems reading file '%s'\n", input_file);
            exit(1);
        }

        /* add floor to locations */
        for (locations_counter = 0; locations_counter < 8; locations_counter++) {
            locations[locations_counter][0] = locations_counter;
            locations[locations_counter][1] = 0;
        }

        printf("%d\n", drop_rocks(buffer, 1000000000000));

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
