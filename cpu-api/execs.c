#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {

    printf("I AM BORN!\n");

    int rc = fork();
    int hellod = 0;
    int status;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    else if (rc == 0) {
        printf("CHILD! pid: %d\n", (int) getpid());
    }

    else {
        int rc_wait = waitpid(rc, &status, __W_CONTINUED);
        printf("PARENT! %d pid: %d\nstatus: %d\n", rc, (int) getpid(), 23);
    }
}