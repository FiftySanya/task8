#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void measure_qsort_time(int *arr, size_t n, const char *description) {
    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare_int);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %f секунд\n", description, time_spent);
}

int main() {
    size_t n = 10000000;
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("malloc");
        return 1;
    }

    // 1. Відсортований масив
    for (size_t i = 0; i < n; i++) arr[i] = i;
    measure_qsort_time(arr, n, "Відсортований масив");

    // 2. Зворотньо відсортований масив
    for (size_t i = 0; i < n; i++) arr[i] = n - i;
    measure_qsort_time(arr, n, "Зворотньо відсортований масив");

    // 3. Масив з однаковими елементами
    for (size_t i = 0; i < n; i++) arr[i] = 42;
    measure_qsort_time(arr, n, "Масив з однаковими елементами");

    // 4. Випадковий масив (для порівняння)
    for (size_t i = 0; i < n; i++) arr[i] = rand() % n;
    measure_qsort_time(arr, n, "Випадковий масив");

    free(arr);
    return 0;
}
