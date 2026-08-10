#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("I AM BORN!\n");

    int rc = fork();
    int hellod = 0;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    else if (rc == 0) {
        hellod = 1;
        printf("hello!\n");
    }

    printf("goodbye!\n");
}