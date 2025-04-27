#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int is_sorted(int *arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) return 0;
    }
    return 1;
}

void test_qsort() {
    // Тест 1: Порожній масив
    int arr1[] = {};
    qsort(arr1, 0, sizeof(int), compare_int);
    printf("Тест 1 (порожній): %s\n", is_sorted(arr1, 0) ? "Пройдено" : "Не пройдено");

    // Тест 2: Один елемент
    int arr2[] = {1};
    qsort(arr2, 1, sizeof(int), compare_int);
    printf("Тест 2 (один елемент): %s\n", is_sorted(arr2, 1) ? "Пройдено" : "Не пройдено");

    // Тест 3: Два елементи
    int arr3[] = {2, 1};
    qsort(arr3, 2, sizeof(int), compare_int);
    printf("Тест 3 (два елементи): %s\n", is_sorted(arr3, 2) ? "Пройдено" : "Не пройдено");

    // Тест 4: Відсортований масив
    int arr4[] = {1, 2, 3, 4, 5};
    qsort(arr4, 5, sizeof(int), compare_int);
    printf("Тест 4 (відсортований): %s\n", is_sorted(arr4, 5) ? "Пройдено" : "Не пройдено");

    // Тест 5: Зворотньо відсортований
    int arr5[] = {5, 4, 3, 2, 1};
    qsort(arr5, 5, sizeof(int), compare_int);
    printf("Тест 5 (зворотній): %s\n", is_sorted(arr5, 5) ? "Пройдено" : "Не пройдено");

    // Тест 6: З дублікатами
    int arr6[] = {3, 1, 2, 3, 4};
    qsort(arr6, 5, sizeof(int), compare_int);
    printf("Тест 6 (дублікати): %s\n", is_sorted(arr6, 5) ? "Пройдено" : "Не пройдено");

    // Тест 7: Випадковий
    int arr7[] = {4, 2, 5, 1, 3};
    qsort(arr7, 5, sizeof(int), compare_int);
    printf("Тест 7 (випадковий): %s\n", is_sorted(arr7, 5) ? "Пройдено" : "Не пройдено");
}

int main() {
    test_qsort();
    return 0;
}
