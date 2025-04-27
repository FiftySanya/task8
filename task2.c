#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("data.bin", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    if (write(fd, data, sizeof(data)) != sizeof(data)) {
        perror("write");
        close(fd);
        return 1;
    }

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    unsigned char buffer[4];
    ssize_t count = read(fd, buffer, 4);
    if (count == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Зчитано %zd байтів: ", count);
    for (size_t i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
