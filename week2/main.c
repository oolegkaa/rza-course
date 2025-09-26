#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Find minimum value in an array of integers
int FindMinimum(const int* signals, int size) {
    if (size <= 0) {
        return INT_MAX;
    }
    
    int min = signals[0];
    for (int i = 1; i < size; i++) {
        if (signals[i] < min) {
            min = signals[i];
        }
    }
    
    return min;
}

// Find maximum value in an array of integers
int FindMaximum(const int* signals, int size) {
    if (size <= 0) {
        return INT_MIN;
    }
    
    int max = signals[0];
    for (int i = 1; i < size; i++) {
        if (signals[i] > max) {
            max = signals[i];
        }
    }
    
    return max;
}

// Find average value in an array of integers
double FindAverage(const int* signals, int size) {
    if (size <= 0) {
        return INT_MIN;
    }
    
    int sum = 0;
    double average = 0;
    for (int i = 0; i < size; i++) {
        sum += signals[i];
    }

    average = (double)sum / (double)size;

    return average;
}

// Find minimum index in an array of integers
int FindMinimumIndex(const int* signals, int size) {
    if (size <= 0) {
        return INT_MIN;
    }
    
    int index = 0;
    int min = signals[0];
    for (int i = 1; i < size; i++) {
        if (signals[i] < min) {
            min = signals[i];
            index = i;
        }
    }
    
    return index;
}

// Read integer array from console
// Реализована только проверка на буквы, однако если попытаться ввести
// число с плавающей запятой, то программа будет работать некорректно
void readArray(int *console_signals, int size2) {  
    if (size2 <= 0) {
       printf("Пустой массив \n");
       return;
    }     
    for(int i = 0; i < size2; i++) {  
        printf("Элемент [%d]: ", i);  
        // Проверка корректности ввода  
        while (scanf("%d", &console_signals[i]) != 1) {  
            printf("Ошибка ввода! Введите целое число: ");  
            // Очищаем буфер ввода  
            while (getchar() != '\n');  
        }  
    }  
}  

// Пузырьковая сортировка
void PSort(int *console_signals, int size2) {
    if (size2 <= 0) {
        return;
    }
    for (int i = 0; i < size2 - 1; i++) {  
        for (int j = 0; j < size2 - i - 1; j++) {  
            if (console_signals[j] > console_signals[j + 1]) {  
            int temp = console_signals[j];  
            console_signals[j] = console_signals[j + 1];  
            console_signals[j + 1] = temp;  
            }  
        }  
    }  
}

int main() {
    // Example signal data
    int signals[] = {5, -3, 10, 1, 8, -7, 4, 2};
    // Для случая пустого массива расскоментировать строку ниже и настроить 
    // CMakeLists.txt
    // int signals[] = {};
    int size = sizeof(signals) / sizeof(signals[0]);
    int size2;

    int min_value = FindMinimum(signals, size);
    int max_value = FindMaximum(signals, size);
    double average_value = FindAverage(signals, size);
    int min_index = FindMinimumIndex(signals, size);

    printf("Signals: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", signals[i]);
    }
    printf("\n");
    
    printf("Minimum value: %d\n", min_value);
    printf("Maximum value: %d\n", max_value);
    printf("Average value: %f\n", average_value);
    printf("Index of minimum value: %d\n", min_index);

    // Инициализация массива для заполнения с консоли
    printf("Введите размер массива: ");  
    while (scanf("%d", &size2) != 1) {  
            printf("Ошибка ввода! Введите целое число: ");  
            // Очищаем буфер ввода  
            while (getchar() != '\n');  
        }  
    int *console_signals = (int*)malloc(size2 * sizeof(int));  
    if (console_signals == NULL) {  
        printf("Ошибка выделения памяти\n");  
        return 1;  
    }  

    readArray(console_signals, size2);
    if (size2 > 0) {
        printf("\nВведенный массив:\n");  
        for(int i = 0; i < size2; i++) {  
            printf("%d ", console_signals[i]);  
        }
     PSort(console_signals, size2);
    printf("\nВведенный массив после пузырьковой сортировки:\n");  
    for(int i = 0; i < size2; i++) {  
        printf("%d ", console_signals[i]);  
    }  
    }  

   

    // Освобождаем память  
    free(console_signals);  

    return 0;
}