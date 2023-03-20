/* --- Advent of Code 2023 - Day 7: No Space Left On Device --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_DIRS 256

/* key-value pair struct */
typedef struct {
    char *key;
    int value;
} dict;

/* add new directory to the dictionary */
void add_dir(dict dirs[], int *dir_count, const char *path, int size) {
    /* check if directory already exists */
    for (int i = 0; i < *dir_count; i++) {
        if (!strcmp(dirs[i].key, path)) {
            return;
        }
    }

    /* directory isn't already in the dictionary */
    dirs[*dir_count].key = strdup(path);                    /* set path for directory */
    dirs[*dir_count].value = size;                          /* set size for directory */
    (*dir_count)++;                                         /* increment directory count */

    return;
}

/* update directory sizes */
void update_dirs(dict dirs[], int dirs_count, const char *path, int size) {
    for (int i = 0; i < dirs_count; i++) {
        if (!strcmp(dirs[i].key, path)) {
            dirs[i].value += size;
            break;
        }
    }

    return;
}

/* create new path by appending dir_name to path and writing it to path_buffer */
void create_path(const char *path, const char *dir_name, char *path_buffer, size_t path_buffer_len) {
    snprintf(path_buffer, path_buffer_len, "%s/%s", path, dir_name);
    return;
}

dict *check_directories(FILE *fp, int *dir_count) {
    char buffer[MAX_LENGTH];
    char path_buffer[MAX_LENGTH];

    char *curr_path;                                            /* current path */
    dict *dirs = (dict *) calloc(MAX_DIRS, sizeof(dict));       /* dictionary for directories */

    while (fgets(buffer, MAX_LENGTH - 1, fp) != NULL) {
        if (!strncmp(buffer, "$", 1)) {
            /* ls: nothing to do */
            if (!strncmp(buffer + 2, "ls", 2)) {
                continue;

            } else if (!strncmp(buffer + 2, "cd", 2)) {
                /* cd /: change to root directory */
                if (!strncmp(buffer + 5, "/", 1)) {
                    create_path("", "root", path_buffer, strlen("/root") + 1);
                    curr_path = strdup(path_buffer);
                    add_dir(dirs, dir_count, curr_path, 0);

                /* cd ..: change to parent directory */
                } else if (!strncmp(buffer + 5, "..", 2)) {
                    char *last_slash = strrchr(curr_path, '/');
                    if (last_slash != NULL) *last_slash = '\0';

                /* cd <dir_name>: change to child directory */
                } else {
                    /* get directory name and remove newline character */
                    char *dir_name = strstr(buffer, "$ cd ") + 5;
                    dir_name[strcspn(buffer, "\n") - strlen("$ cd ")] = '\0';

                    create_path(curr_path, dir_name, path_buffer, strlen(curr_path) + strlen(dir_name) + 2);
                    curr_path = strdup(path_buffer);
                    add_dir(dirs, dir_count, curr_path, 0);
                }
            }

        /* dir <dir_name>: nothing to do */
        } else if (!strncmp(buffer, "dir", 3)) {
            continue;

        /* <filesize>: update sizes of directories */
        } else {
            int file_size;
            sscanf(buffer, "%d", &file_size);
            char *dir = malloc(strlen(curr_path) + 1);
            strcpy(dir, curr_path);

            /* update all parent directories by adding the file size */
            while (strncmp(dir, "", 1)) {
                update_dirs(dirs, *dir_count, dir, file_size);
                char *last_slash = strrchr(dir, '/');
                if (last_slash != NULL) *last_slash = '\0';
            }

            free(dir);
        }
    }

    free(curr_path);
    return dirs;
}

/* solution part-1 */
int part_1(char input_file[]) {
    FILE *fp = fopen(input_file, "r");

    /* file opened successfully */
    if (fp != NULL) {
        int dir_count = 0;
        dict *dirs = check_directories(fp, &dir_count);

        /* add the size of all directories smaller than 100000 */
        int total_size = 0;
        for (int i = 0; i < dir_count; i++) {
            if (dirs[i].value < 100000) {
                total_size += dirs[i].value;
            }
        }

        printf("%d\n", total_size);

        /* free memory */
        for (int i = 0; i < dir_count; i++) {
            free(dirs[i].key);
        }
        free(dirs);

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
        int dir_count = 0;
        dict *dirs = check_directories(fp, &dir_count);

        /* total disk space available to the filesystem is 70000000 */
        int free_space = 70000000 - dirs[0].value;

        /* to run the update,  unused space of at least 30000000 is needed */
        int needed_space = 30000000 - free_space;

        /* choose to delete the smallest directory that's big enough */
        int smallest_dir = dirs[0].value;
        for (int i = 0; i < dir_count; i++) {
            if (dirs[i].value >= needed_space) {
                smallest_dir = smallest_dir > dirs[i].value ? dirs[i].value : smallest_dir;
            }
        }

        printf("%d\n", smallest_dir);

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
