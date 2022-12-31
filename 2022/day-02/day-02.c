/* --- Advent of Code 2022 - Day 2: Rock Paper Scissor --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int solution(char part[], char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* solution part-1 */
    if (!strcmp(part, "-p1")) {
        // TODO

        return 0;
    }

    /* solution part-2 */
    if (!strcmp(part, "-p2")) {
        // TODO

        return 0;
    }
}

/* main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -p[1|2] <input-file>\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "-p1") || !strcmp(argv[1], "-p2")) {
        solution(argv[1], argv[2]);
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
