/* --- Advent of Code 2023 - Day 25: Full of Hot Air --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 256
#define BASE 5

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];
    long long base10_res = 0;

    /* file opened successfully */
    if (fp != NULL) {
        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            long long base10_sum = 0;

            /* convert SNAFU to base 10 */
            for (int pow_val = strlen(buffer) - 2; pow_val >= 0; pow_val--) {
                switch (buffer[strlen(buffer) - 2 - pow_val]) {
                    case '-':
                        base10_sum += pow(BASE, pow_val) * -1;
                        break;
                    case '=':
                        base10_sum += pow(BASE, pow_val) * -2;
                        break;
                    default:
                        base10_sum += pow(BASE, pow_val) * (buffer[strlen(buffer) - 2 - pow_val] - '0');
                }
            }

            base10_res += base10_sum;
        }

        /* convert base 10 result to base 5 */
        int base5_res[MAX_LENGTH];
        int len = 0;

        for (len = 0; base10_res > 0; len++) {
            base5_res[len] = base10_res % BASE;
            base10_res = base10_res / BASE;
        }

        /* adjust base 5 to SNAFU */
        int carry = 0;
        for (int i = 0; i < len; i++) {
            if ((base5_res[i] + carry) <= 2) {
                base5_res[i] = base5_res[i] + carry;
                carry = 0;
            } else {
                base5_res[i] = (base5_res[i] + carry) - 5;
                carry = 1;
            }
        }

        /* print result in SNAFU */
        for (int i = len - 1; i >= 0; i--) {
            switch (base5_res[i]) {
                case -1:
                    printf("-");
                    break;
                case -2:
                    printf("=");
                    break;
                default:
                    printf("%d", base5_res[i]);
            }
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

    /* file opened successfully */
    if (fp != NULL) {
        printf(":)\n");

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
