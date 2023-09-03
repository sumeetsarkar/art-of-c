#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLAG_LEN 2

// https://en.cppreference.com/w/cpp/io/c/fopen
const char *FLAG_READ = "-r";
const char *FLAG_WRITE = "-w";
const char *FLAG_APPEND = "-a";

void hint_usage();
void read_file(char *path);
void write_file(char *path);
void append_file(char *path);

int main(int argc, char **argv) {
    if (argc < 2) {
        hint_usage();
        return EXIT_SUCCESS;
    }

    char *path = "./tmp/file_io_basic.txt";
    char *arg_mode = argv[1];

    if (strncmp(arg_mode, FLAG_READ, MAX_FLAG_LEN) == 0) {
        read_file(path);

    } else if(strncmp(arg_mode, FLAG_WRITE, MAX_FLAG_LEN) == 0) {
        write_file(path);

    } else if(strncmp(arg_mode, FLAG_APPEND, MAX_FLAG_LEN) == 0) {
        append_file(path);
    }

    return EXIT_SUCCESS;
}

void read_file(char *path) {
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        perror("\nFile opening failed");
        exit(EXIT_FAILURE);
    }

    int c; // int required to read EOF
    while ((c = getc(fptr)) != EOF) {
        putchar(c);
    }
    fclose(fptr);
}

void write_file(char *path) {    
    FILE *fptr = fopen(path, "w");
    if (fptr == NULL) {
        perror("\nFile opening failed");
        exit(EXIT_FAILURE);
    }

    fputs("\nhello mom!", fptr);
    fclose(fptr);
}

void append_file(char *path) {
    FILE *fptr = fopen(path, "a");
    if (fptr == NULL) {
        perror("\nFile opening failed");
        exit(EXIT_FAILURE);
    }

    fputs("\nhello mom!", fptr);
    fclose(fptr);
}

void hint_usage() {
    printf("\nUsage: <prog> -r | -w\n");
}

