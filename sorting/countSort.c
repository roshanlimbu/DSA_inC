#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define HIGHEST 40

int getHighest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int n) {
    int temp[MAX];
    int count[HIGHEST + 1] = {0};
    int max = getHighest(arr, n);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[MAX] = {12, 9, 5, 7, 8, 13, 14, 15, 12, 40};
    int i;

    printf("Before sorting: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countsort(arr, MAX);

    printf("\nAfter Sorting: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
