/* --- Advent of Code 2023 - Day 10: Cathode-Ray Tube --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

/* store number of cycles, value in register x and final score */
static int no_cycles;
static int x;
static int score;

/* increment the cycle counter and update the score for given cycles */
void tick() {
    if (no_cycles == 20 || no_cycles == 60 || no_cycles == 100 || no_cycles == 140 || no_cycles == 180 || no_cycles == 220) {
        score += no_cycles * x;
    }
    no_cycles++;
}


/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* inialize variables */
    no_cycles = 1;
    x = 1;
    score = 0;

    /* file opened successfully */
    if (fp != NULL) {
        /* read the opearations and execute them line by line */
        while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
            /* noop takes 1 cycle, addx takes 2 cycles */
            if (!strncmp(buffer, "noop", 4)) {
                tick();
            } else if (!strncmp(buffer, "addx", 4)) {
                tick();
                tick();
                int i = atoi(&(buffer[4]));
                x += i;
            } else {
                fprintf(stderr, "Unknown instruction: %s", buffer);
                exit(1);
            }
        }

        printf("%d\n", score);

    /* file not found */
    } else {
        fprintf(stderr,"Problems opening file '%s'\n", input_file);
        exit(1);
    }

    return 0;
}

/* increment the cycle counter and print a pixel */
void tick_to_print() {
    int printer_pos = no_cycles % 40;

    /* if the x value(+1 / -1) is in range of the printer, a #is printed */
    if (printer_pos == x - 1 || printer_pos == x || printer_pos == x + 1) {
        printf("#");
    }
    else {
        printf(".");
    }

    if (++no_cycles % 40 == 0) {
        printf("\n");
    }
}

/* solution part-2 */
int part_2(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* inialize variables */
    no_cycles = 0;
    x = 1;
    score = 0;

    /* file opened successfully */
    if (fp != NULL) {
        while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
            /* noop takes 1 cycle, addx takes 2 cycles */
            if (!strncmp(buffer, "noop", 4)) {
                tick_to_print();
            } else if (!strncmp(buffer, "addx", 4)) {
                tick_to_print();
                tick_to_print();
                int i = atoi(&(buffer[4]));
                x += i;
            } else {
                fprintf(stderr, "Unknown instruction: %s", buffer);
                exit(1);
            }
        }

    /* file not found */
    } else {
        fprintf(stderr,"Problems opening file '%s'\n", input_file);
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
