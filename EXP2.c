/* Ex.No 2: File Copying using system calls */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF 1024

int main(int argc, char *argv[]) {
    int fd_src, fd_dst;
    char buf[BUF];
    ssize_t n;

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src < 0) {
        perror("open source");
        return 1;
    }

    fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dst < 0) {
        perror("open dest");
        close(fd_src);
        return 1;
    }

    while ((n = read(fd_src, buf, BUF)) > 0) {
        if (write(fd_dst, buf, n) != n) {
            perror("write");
            close(fd_src);
            close(fd_dst);
            return 1;
        }
    }

    close(fd_src);
    close(fd_dst);
    return 0;
}
