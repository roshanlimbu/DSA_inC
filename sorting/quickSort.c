#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
  int pivot = arr[high];  // Choose the rightmost element as the pivot
  int i = (low - 1);      // Index of the smaller element

  for (int j = low; j <= high - 1; j++) {
    // If the current element is smaller than or equal to the pivot
    if (arr[j] <= pivot) {
      i++;  // Increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // Partition the array into two sub-arrays and get the pivot index
    int pi = partition(arr, low, high);

    // Recursively sort the sub-arrays
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  quickSort(arr, 0, n - 1);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
