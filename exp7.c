/* INTER-PROCESS COMMUNICATION USING PIPE (Parent → Child) */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char message[] = "Hello from Parent!";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {         // Child
        close(fd[1]);            // close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {                     // Parent
        close(fd[0]);            // close read end
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    return 0;
}
