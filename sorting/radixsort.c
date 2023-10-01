#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to get the maximum element from an array
int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Function to perform counting sort on a particular digit place (exp)
void countSort(int arr[], int n, int exp) {
  int output[MAX];
  int count[10] = {0};
  // Count the occurrences of digits at the current digit place
  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }
  // Update the count array to store the actual position of the digits
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  // Build the output array by placing elements in their sorted order
  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  // Copy the sorted elements back to the original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
  int max = getMax(arr, n);

  // Perform counting sort for every digit place (from least significant to most
  // significant)
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSort(arr, n, exp);
  }
}

int main() {
  int arr[MAX] = {45, 23, 123, 245, 450, 111, 44, 679, 123, 235};
  int i;

  printf("Before sorting: ");
  for (i = 0; i < MAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  radixSort(arr, MAX);

  printf("After Sorting: ");
  for (i = 0; i < MAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
