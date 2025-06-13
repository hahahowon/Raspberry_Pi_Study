#include <stdio.h>      // printf, perror, BUFSIZ
#include <stdlib.h>     // exit, NULL
#include <unistd.h>     // fork, pipe, dup2, execl, read, close, _exit
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // waitpid, WEXITSTATUS


int main(int argc, char **argv){
    pid_t pid;
    int pfd[2];
    char line[BUFSIZ];
    int status;

    printf("[Parent] Start of program\n");

    if(pipe(pfd)<0){
        perror("pipe()");
        return -1;
    }
    printf("[Parent] Pipe created: read=%d, write=%d\n", pfd[0], pfd[1]);

    if((pid = fork()) < 0){
        perror("fork");
        return -1;
    } else if(pid == 0){
        // Child Process
        printf("[Child] In child process (PID: %d)\n", getpid());

        close(pfd[0]);
        printf("[Child] Closed read end of pipe\n");

        dup2(pfd[1], 1); // Redirect stdout to write end of pipe
        printf("[Child] Duplicated write end to stdout (fd 1)\n");

        execl("/bin/date", "date", NULL);

        // If execl fails:
        perror("[Child] execl failed");
        close(pfd[1]);
        _exit(127);
    } else {
        // Parent Process
        printf("[Parent] In parent process (PID: %d), child PID: %d\n", getpid(), pid);

        close(pfd[1]);
        printf("[Parent] Closed write end of pipe\n");

        int n = read(pfd[0], line, BUFSIZ);
        if(n < 0){
            perror("read()");
            return -1;
        }

        line[n] = '\0'; // Null-terminate the string
        printf("[Parent] Received from child: %s\n", line);

        waitpid(pid, &status, 0);
        printf("[Parent] Child exited with status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
