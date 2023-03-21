/* --- Advent of Code 2023 - Day 13: Distress Signal --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

typedef struct list {
    int len;
    int is_int;
    union {
        int int_val;
        struct list **vals;
    };
} packet_list;

/* create a new empty list */
packet_list *create_list(void) {
    packet_list *list = (packet_list *) malloc(sizeof(packet_list));

    list->len = 0;
    list->is_int = 0;
    list->vals = NULL;

    return list;
}

/* create a new list with a single integer */
packet_list *create_int_list(int i) {
    packet_list *list = (packet_list *) malloc(sizeof(packet_list));

    list->len = 1;
    list->is_int = 1;
    list->int_val = i;

    return list;
}

/* add an item to the list */
void add_to_list(packet_list *list, packet_list *item) {
    if (list->len == 0) {
        list->vals = (packet_list **) malloc(sizeof(packet_list *));
    } else {
        list->vals = (packet_list **) realloc(list->vals, sizeof(packet_list *) * (list->len + 1));
    }

    list->is_int = 0;
    list->vals[list->len++] = item;
}

/* create divider packets */
packet_list *create_div_list(int i) {
    packet_list *list = create_list();
    packet_list *tmp = create_list();

    add_to_list(tmp, create_int_list(i));
    add_to_list(list, tmp);

    return list;
}

/* parse the input file */
packet_list *parse_list(char *buffer, int *start_pos) {
    packet_list *list;
    int i;
    char buf[MAX_LENGTH];

    switch (buffer[*start_pos]) {
        /* parse list of one or more items */
        case '[':
            list = create_list();
            if (buffer[(*start_pos) + 1] != ']') {
                do {
                    (*start_pos)++;
                    add_to_list(list, parse_list(buffer, start_pos));
                } while (buffer[*start_pos] == ',');
            } else {
                (*start_pos)++;
            }

            (*start_pos)++;
            break;

        /* parse single integer of one or more digits */
        default:
            for (i = 0; isdigit(buffer[*start_pos]); i++, (*start_pos)++)
                buf[i] = buffer[*start_pos];
            buf[i] = '\0';
            list = create_int_list(atoi(buf));
            break;
    }

    return list;
}

/* compare two integers */
int compare(const int a, const int b) {
    if (a < b) {
        return 1;
    } else if (a > b) {
        return -1;
    } else {
        return 0;
    }
}

/* determine if two pairs are in order */
int compare_pairs(packet_list *a, packet_list *b) {
    /* int and int */
    if (a->is_int && b->is_int) {
        return compare(a->int_val, b->int_val);

    /* list[...] and list[...] */
    } else if (!a->is_int && !b->is_int) {
        int cmp = 0;
        int min_len = a->len < b->len ? a->len : b->len;

        for (int i = 0; i < min_len; i++) {
            cmp = compare_pairs(a->vals[i], b->vals[i]);
            if (cmp != 0) {
                return cmp;
            }
        }

        return compare(a->len, b->len);

    /* list[...] and int */
    } else if (!a->is_int && b->is_int) {
        packet_list *tmp = create_list();
        add_to_list(tmp, b);
        int cmp = compare_pairs(a, tmp);
        free(tmp);
        return cmp;

    /* int and list[...] */
    } else if (a->is_int && !b->is_int) {
        packet_list *tmp = create_list();
        add_to_list(tmp, a);
        int cmp = compare_pairs(tmp, b);
        free(tmp);
        return cmp;
    }

    fprintf(stderr, "Error: compare_pairs() got invalid arguments a->is_int=%d, b->is_int=%d\n", a->is_int, b->is_int);
    exit(1);
}

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");
    char buffer[MAX_LENGTH];

    /* file opened successfully */
    if (fp != NULL) {
        int idx = 1;
        int sum_of_indices = 0;

        while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
            int start_pos = 0;
            packet_list *list1 = parse_list(buffer, &start_pos);
            fgets(buffer, MAX_LENGTH - 1, fp);

            start_pos = 0;
            packet_list *list2 = parse_list(buffer, &start_pos);
            fgets(buffer, MAX_LENGTH - 1, fp);

            /* compare pairs and add index to sum if pair is in order */
            if (compare_pairs(list1, list2) == 1) {
                sum_of_indices += idx;
            }
            idx++;

            free(list1);
            free(list2);
        }

        printf("%d\n", sum_of_indices);

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
        int divider_packet_1_idx = 1;
        int divider_packet_2_idx = 2;

        packet_list *div_1 = create_div_list(2);
        packet_list *div_2 = create_div_list(6);

        while (fgets(buffer, MAX_LENGTH, fp) != NULL) {
            /* get first packet from pair */
            int start_pos = 0;
            packet_list *list = parse_list(buffer, &start_pos);
            fgets(buffer, MAX_LENGTH - 1, fp);

            /* find position of divider packet by comparing with first packet */
            if (compare_pairs(list, div_1) == 1) divider_packet_1_idx++;
            if (compare_pairs(list, div_2) == 1) divider_packet_2_idx++;

            free(list);

            /* get second packet from pair */
            start_pos = 0;
            list = parse_list(buffer, &start_pos);
            fgets(buffer, MAX_LENGTH - 1, fp);

            /* find position of divider packet by comparing with second packet */
            if (compare_pairs(list, div_1) == 1) divider_packet_1_idx++;
            if (compare_pairs(list, div_2) == 1) divider_packet_2_idx++;

            free(list);
        }

        free(div_1);
        free(div_2);

        int decoder_key = divider_packet_1_idx * divider_packet_2_idx;
        printf("%d\n", decoder_key);

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
