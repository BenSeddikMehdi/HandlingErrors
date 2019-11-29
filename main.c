#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // open the file
    int fd = open(argv[1], O_RDONLY);
    // read its contents and print them to stdout
    char c;
    while (read(fd, &c, 1) > 0) {
        fputc(c, stdout);
    }
    close(fd);
    return 0;
}