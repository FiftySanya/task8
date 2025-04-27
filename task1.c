#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(void) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Установимо write-end pipe в неблокуючий режим
    int flags = fcntl(pipefd[1], F_GETFL);

    if (flags == -1) {
        perror("fcntl(F_GETFL)");
        exit(EXIT_FAILURE);
    }

    if (fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl(F_SETFL)");
        exit(EXIT_FAILURE);
    }

    // Підготуємо великий буфер
    size_t nbytes = 100000;
    char *buffer = malloc(nbytes);
    if (!buffer) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 'A', nbytes);

    // Спроба одноразово записати nbytes байт
    ssize_t written = write(pipefd[1], buffer, nbytes);
    if (written == -1) {
        if (errno == EAGAIN) {
            printf("write() повернув -1 з errno=EAGAIN (буфер заповнений)\n");
        } else {
            perror("write");
        }
        free(buffer);
        exit(EXIT_FAILURE);
    }

    printf("Requested write: %zu bytes\n", nbytes);
    printf("Actually written: %zd bytes\n", written);

    close(pipefd[0]);
    close(pipefd[1]);
    free(buffer);
    
    return 0;
}
