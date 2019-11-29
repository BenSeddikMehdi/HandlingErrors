#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(X) ({\
                    int __val = (X); (__val == -1 ? \
                 ({fprintf(stderr, "ERROR: "__FILE__ ": %d %s\n", __LINE__, strerror(errno));\
                  exit(-1); -1;}) : __val);\
                  })

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage %s <filename>\n", argv[0]);
        exit(-1);
    }
    // open the file
    int fd = open(argv[1], O_RDONLY);
    CHECK(fd);

    // read its contents and print them to stdout
    char c;
    while (CHECK(read(fd, &c, 1)) > 0) {
        fputc(c, stdout);
    }
    close(fd);
    return 0;
}