#include <stdio.h>
#include <limits.h>

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

int main() {
    // Example signal data
    int signals[] = {5, -3, 10, 1, 8, -7, 4, 2};
    // Для случая пустого массива расскоментировать строку ниже и настроить CMakeLists.txt
    // int signals[] = {};
    int size = sizeof(signals) / sizeof(signals[0]);
    
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

    return 0;
}