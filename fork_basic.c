#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("[%d] Hello world\n", getpid());

    int i = 0;
    for (; i < 2; i ++) {
        printf("[%d] [%d] For loop Pre-Fork\n", getpid(), i);
        fork();
        printf("[%d] [%d] For loop Post-Fork\n", getpid(), i);
    }

    printf("[%d] [%d]After fork: Hello world\n", getpid(), i);
    return EXIT_SUCCESS;
}

