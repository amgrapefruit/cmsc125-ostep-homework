#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main() {
    int x = 100;
    printf("x initialized as %d (pid: %i)\n", x, (int) getpid());

    int pfd = open("./fc_output.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("pfd initialized as: %d\n", pfd);
    int bytes;
    char buf[20];
    ssize_t bytes_written;
    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    else if (rc == 0) {
        x++;
        printf("x in child: %d (pid: %i)\n", x, (int) getpid());
        printf("pfd in child: %d\n", pfd);

        // child writes
        strcpy(buf, "hi from child\n");
        bytes = strlen(buf);
        bytes_written = write(pfd, buf, bytes);
    }

    else {
        x--;
        int rc_wait = wait(NULL);
        printf("x in parent: %d (pid: %i parent of %i)\n", x, (int) getpid(), rc);
        printf("pfd in parent: %d\n", pfd);
        
        // parent writes
        strcpy(buf, "hi from parent\n");
        bytes = strlen(buf);
        bytes_written = write(pfd, buf, bytes);
    }
}