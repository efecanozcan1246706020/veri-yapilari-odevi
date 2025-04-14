#include <stdio.h>
#include <stdlib.h>

void sortDesc(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void özelSıralama(int arr[], int n) {
    sortDesc(arr, n);
    int yeni[n];
    int left = 0, right = n - 1, i = 0;
    while (left <= right) {
        if (i % 2 == 0)
            yeni[i] = arr[left++];
        else
            yeni[i] = arr[right--];
        i++;
    }

    printf("Yeni sıralama: ");
    for (i = 0; i < n; i++)
        printf("%d ", yeni[i]);
    printf("\n");
}

int main() {
    int dizi[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(dizi)/sizeof(dizi[0]);

    özelSıralama(dizi, n);

    return 0;
}
