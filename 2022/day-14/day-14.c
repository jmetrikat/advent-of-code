/* --- Advent of Code 2023 - Day 14: Regolith Reservoir --- */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define HEIGHT 1000
#define WIDTH 1000

/* cave map consists of air, wall and sand */
typedef enum { AIR,
               WALL,
               SAND } cave_materials;

/* read cave map from input file */
cave_materials **get_map(FILE *fp, int *highest_y_coordinate) {
    char buffer[MAX_LENGTH];

    /* allocate memory for cave_map */
    cave_materials **cave_map = (cave_materials **) malloc(sizeof(cave_materials *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        cave_map[i] = (cave_materials *) malloc(sizeof(cave_materials) * WIDTH);
        for (int j = 0; j < WIDTH; j++) {
            cave_map[i][j] = AIR;
        }
    }

    /* read input file and fill map with walls */
    while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
        int prev_x = 0, prev_y = 0;
        int x, y;
        char *p = buffer;

        /* read coordinates */
        while (sscanf(p, "%d,%d", &x, &y) == 2) {
            /* start drawing walls when second pair of coordinates is given */
            if (prev_x && prev_y) {
                /* draw vertical wall */
                if (x == prev_x) {
                    /* draw wall to the right */
                    if (y > prev_y) {
                        for (int i = prev_y; i <= y; i++) {
                            cave_map[x][i] = WALL;
                        }

                    /* draw wall to the left */
                    } else {
                        for (int i = y; i <= prev_y; i++) {
                            cave_map[x][i] = WALL;
                        }
                    }

                /* draw horizontal wall */
                } else {
                    /* draw wall to the bottom */
                    if (x > prev_x) {
                        for (int i = prev_x; i <= x; i++) {
                            cave_map[i][y] = WALL;
                        }

                    /* draw wall to the top */
                    } else {
                        for (int i = x; i <= prev_x; i++) {
                            cave_map[i][y] = WALL;
                        }
                    }
                }

                /* update highest_y_coordinate */
                if (highest_y_coordinate != NULL) {
                    *highest_y_coordinate = y > *highest_y_coordinate ? y : *highest_y_coordinate;
                }
            }

            /* move pointer to next pair of coordinates */
            while (isdigit(*p) || *p == ',') p++;
            if (isblank(*p)) p += 4;

            prev_x = x;
            prev_y = y;
        }
    }

    return cave_map;
}

/* pour sand from the top of the cave as long as it falls into the abyss */
int pour_sand(cave_materials **cave_map) {
    int sand[2] = {500, 0}; /* store x and y coordinates of falling sand */

    while (1) {
        /* sand is falling into the abyss */
        if (sand[1] == WIDTH - 1 || cave_map[sand[0]][sand[1]] == SAND) {
            return 0;
        }

        /* sand can move one step down */
        if (cave_map[sand[0]][sand[1] + 1] == AIR) {
            sand[1]++;
        /* sand can move one step down and to the left */
        } else if (cave_map[sand[0] - 1][sand[1] + 1] == AIR) {
            sand[0]--;
            sand[1]++;
        /* sand can move one step down and to the right */
        } else if (cave_map[sand[0] + 1][sand[1] + 1] == AIR) {
            sand[0]++;
            sand[1]++;
        /* sand can't move anymore */
        } else {
            cave_map[sand[0]][sand[1]] = SAND;
            return 1;
        }
    }
}

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");

    /* file opened successfully */
    if (fp != NULL) {
        cave_materials **cave_map = get_map(fp, NULL);

        /* pour sand and count units that don't fall into the abyss */
        int result = 0;
        while (pour_sand(cave_map)) {
            result++;
        }

        printf("%d\n", result);

        /* free the cave_map */
        for (int i = 0; i < HEIGHT; i++) {
            free(cave_map[i]);
        }
        free(cave_map);

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

    /* file opened successfully */
    if (fp != NULL) {
        int highest_y_coordinate = 0;
        cave_materials **cave_map = get_map(fp, &highest_y_coordinate);

        /* add infinite horizontal wall at the bottom of the cave */
        for (int i = 0; i < WIDTH; i++) {
            cave_map[i][highest_y_coordinate + 2] = WALL;
        }

        /* pour sand and count units that don't fall into the abyss */
        int result = 0;
        while (pour_sand(cave_map)) {
            result++;
        }

        printf("%d\n", result);

        /* free the cave_map */
        for (int i = 0; i < HEIGHT; i++) {
            free(cave_map[i]);
        }
        free(cave_map);

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
