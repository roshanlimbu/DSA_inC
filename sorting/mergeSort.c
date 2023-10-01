#include <stdio.h>

// Merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
  int i = 0, j = 0, k = 0;

  // Compare elements from both subarrays and merge them into the original array
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  // Copy any remaining elements from the left subarray (if any)
  while (i < leftSize) {
    arr[k] = left[i];
    i++;
    k++;
  }
  // Copy any remaining elements from the right subarray (if any)
  while (j < rightSize) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int size) {
  if (size < 2) {
    return; // Base case: If the array has 0 or 1 elements, it's already sorted.
  }
  // Calculate the middle index
  int mid = size / 2;
  // Create left and right subarrays
  int left[mid];
  int right[size - mid];
  // Fill the left and right subarrays
  for (int i = 0; i < mid; i++) {
    left[i] = arr[i];
  }
  for (int i = mid; i < size; i++) {
    right[i - mid] = arr[i];
  }
  // Recursively sort the left and right subarrays
  mergeSort(left, mid);
  mergeSort(right, size - mid);
  // Merge the sorted subarrays back into the original array
  merge(arr, left, mid, right, size - mid);
}

int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  mergeSort(arr, size);

  printf("Sorted array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
