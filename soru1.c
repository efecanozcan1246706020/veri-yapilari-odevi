#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int x[SIZE], temp[SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        x[i] = rand() % 1001;
    }

    copyArray(x, temp, SIZE);
    clock_t start = clock();
    insertionSort(temp, SIZE);
    clock_t end = clock();
    double time_insertion = (double)(end - start) / CLOCKS_PER_SEC;

    copyArray(x, temp, SIZE);
    start = clock();
    selectionSort(temp, SIZE);
    end = clock();
    double time_selection = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort Süresi: %f saniye\n", time_insertion);
    printf("Selection Sort Süresi: %f saniye\n", time_selection);

    return 0;
}
