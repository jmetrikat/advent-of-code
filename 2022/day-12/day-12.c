/* --- Advent of Code 2023 - Day 12: Hill Climbing Algorithm --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_HEIGHT 100
#define MAX_WIDTH 100

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];
    char map[MAX_HEIGHT][MAX_WIDTH];

    /* file opened successfully */
    if (fp != NULL) {
        int start[2], end[2];
        int row, col;

        /* generate map */
        for (row = 0; fgets(buffer, MAX_LENGTH - 1, fp); row++) {
            for (col = 0; (buffer[col] >= 'a' && buffer[col] <= 'z') || (buffer[col] == 'S') || (buffer[col] == 'E'); col++) {
                map[row][col] = buffer[col];

                /* find start */
                if (buffer[col] == 'S') {
                    start[0] = col;         /* x coordinate */
                    start[1] = row;         /* y coordinate */
                    map[row][col] = 'a';
                }

                /* find end */
                if (buffer[col] == 'E') {
                    end[0] = col;           /* x coordinate */
                    end[1] = row;           /* y coordinate */
                    map[row][col] = 'z';
                }
            }
        }


        /* use dijikstra algorithm */
        int no_nodes = row * col;
        int *distance = (int *)malloc(sizeof(int) * no_nodes);      /* distance from start to node; distance[end[0] + end[1] * col] has the solution */
        int *visited = (int *)malloc(sizeof(int) * no_nodes);       /* record of visited nodes; 1 = visited, 0 = not visited */
        int **cost = (int **)malloc(sizeof(int *) * no_nodes);      /* altitude difference of nodes; 1 = reachable, ∞ = not reachable */

        for (int i = 0; i < no_nodes; i++) {
            cost[i] = (int *)malloc(sizeof(int) * no_nodes);
        }

        /* initialize distance matrix */
        for (int src = 0; src < no_nodes; src++) {
            for (int dest = 0; dest < no_nodes; dest++) {
                if (src == dest) {
                    /* distance from node to itself is 0 */
                    cost[src][dest] = 0;
                } else {
                    /* distance of all other nodes is "infinity" */
                    cost[src][dest] = no_nodes;

                    /* distance of all adjacent and by elevation recheable nodes is 1 */
                    int src_x = src % col;
                    int src_y = src / col;
                    int dest_x = dest % col;
                    int dest_y = dest / col;

                    if ((abs(src_x - dest_x) == 1 && src_y == dest_y) || (abs(src_y - dest_y) == 1 && src_x == dest_x)) {
                        if (map[dest_y][dest_x] - map[src_y][src_x] <= 1) {
                            cost[src][dest] = 1;
                        }
                    }
                }
            }
        }

        /* initialize distance and visited */
        for (int i = 0; i < no_nodes; i++) {
            distance[i] = cost[start[0] + start[1] * col][i];
            visited[i] = 0;
        }
        visited[start[0] + start[1] * col] = 1;

        /* calculate paths from start to all other nodes */
        for (int i = 0; i < no_nodes; i++) {
            int min_distance = no_nodes;
            int next_node_idx = 0;

            /* find node with minimum distance */
            for (int j = 0; j < no_nodes; j++) {
                if (visited[j] == 0 && distance[j] < min_distance) {
                    min_distance = distance[j];
                    next_node_idx = j;
                }
            }

            /* mark node as visited */
            visited[next_node_idx] = 1;

            /* update distance of all adjacent nodes */
            for (int j = 0; j < no_nodes; j++) {
                if (visited[j] == 0 && distance[j] > min_distance + cost[next_node_idx][j]) {
                    distance[j] = min_distance + cost[next_node_idx][j];
                }
            }
        }

        printf("%d\n", distance[end[0] + end[1] * col]);

        /* free memory */
        for (int i = 0; i < no_nodes; i++)
            free(cost[i]);
        free(cost);
        free(visited);
        free(distance);

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
    char map[MAX_HEIGHT][MAX_WIDTH];

    /* file opened successfully */
    if (fp != NULL) {
        int start[2], end[2];
        int row, col;

        /* generate map */
        for (row = 0; fgets(buffer, MAX_LENGTH - 1, fp); row++) {
            for (col = 0; (buffer[col] >= 'a' && buffer[col] <= 'z') || (buffer[col] == 'S') || (buffer[col] == 'E'); col++) {
                map[row][col] = buffer[col];

                /* find start */
                if (buffer[col] == 'S') {
                    start[0] = col;         /* x coordinate */
                    start[1] = row;         /* y coordinate */
                    map[row][col] = 'a';
                }

                /* find end */
                if (buffer[col] == 'E') {
                    end[0] = col;           /* x coordinate */
                    end[1] = row;           /* y coordinate */
                    map[row][col] = 'z';
                }
            }
        }

        /* use dijikstra algorithm */
        int no_nodes = row * col;
        int *distance = (int *)malloc(sizeof(int) * no_nodes);      /* distance from start to node; distance[end[0] + end[1] * col] has the solution */
        int *visited = (int *)malloc(sizeof(int) * no_nodes);       /* record of visited nodes; 1 = visited, 0 = not visited */
        int **cost = (int **)malloc(sizeof(int *) * no_nodes);      /* altitude difference of nodes; 1 = reachable, ∞ = not reachable */

        for (int i = 0; i < no_nodes; i++) {
            cost[i] = (int *)malloc(sizeof(int) * no_nodes);
        }

        /* initialize distance matrix */
        for (int src = 0; src < no_nodes; src++) {
            for (int dest = 0; dest < no_nodes; dest++) {
                if (src == dest) {
                    /* distance from node to itself is 0 */
                    cost[src][dest] = 0;
                } else {
                    /* distance of all other nodes is "infinity" */
                    cost[src][dest] = no_nodes;

                    /* distance of all adjacent and by elevation recheable nodes is 1 */
                    int src_x = src % col;
                    int src_y = src / col;
                    int dest_x = dest % col;
                    int dest_y = dest / col;

                    if ((abs(src_x - dest_x) == 1 && src_y == dest_y) || (abs(src_y - dest_y) == 1 && src_x == dest_x)) {
                        if (map[dest_y][dest_x] - map[src_y][src_x] <= 1) {
                            cost[src][dest] = 1;
                        }
                    }
                }
            }
        }

        /* check all start positions for shortest path */
        int fewest_steps = no_nodes;

        for (start[0] = 0; start[0] < row; start[0]++) {
            for (start[1] = 0; start[1] < col; start[1]++) {
                if (map[start[1]][start[0]] == 'a') {

                    /* initialize distance and visited */
                    for (int i = 0; i < no_nodes; i++) {
                        distance[i] = cost[start[0] + start[1] * col][i];
                        visited[i] = 0;
                    }
                    visited[start[0] + start[1] * col] = 1;

                    /* calculate paths from start to all other nodes */
                    for (int i = 0; i < no_nodes; i++) {
                        int min_distance = no_nodes;
                        int next_node_idx = 0;

                        /* find node with minimum distance */
                        for (int j = 0; j < no_nodes; j++) {
                            if (visited[j] == 0 && distance[j] < min_distance) {
                                min_distance = distance[j];
                                next_node_idx = j;
                            }
                        }

                        /* mark node as visited */
                        visited[next_node_idx] = 1;

                        /* update distance of all adjacent nodes */
                        for (int j = 0; j < no_nodes; j++) {
                            if (visited[j] == 0 && distance[j] > min_distance + cost[next_node_idx][j]) {
                                distance[j] = min_distance + cost[next_node_idx][j];
                            }
                        }
                    }

                    /* update fewest steps */
                    fewest_steps = fewest_steps >  distance[end[0] + end[1] * col] ? distance[end[0] + end[1] * col] : fewest_steps;
                }
            }
        }

        printf("%d\n", fewest_steps);

        /* free memory */
        for (int i = 0; i < no_nodes; i++)
            free(cost[i]);
        free(cost);
        free(visited);
        free(distance);

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
