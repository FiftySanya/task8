#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Використання: %s файл1 файл2\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];
    char *temp = "temp_swap";

    // Крок 1: Перейменувати file1 у temp
    if (rename(file1, temp) == -1) {
        perror("rename file1 to temp");
        return 1;
    }

    // Крок 2: Перейменувати file2 у file1
    if (rename(file2, file1) == -1) {
        perror("rename file2 to file1");
        
        rename(temp, file1);
        return 1;
    }

    // Крок 3: Перейменувати temp у file2
    if (rename(temp, file2) == -1) {
        perror("rename temp to file2");
        return 1;
    }

    printf("Обмін виконано успішно\n");
    return 0;
}
