#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    
    printf("%d\n", pid);
    return 0;
}
