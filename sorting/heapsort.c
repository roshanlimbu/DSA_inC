#include <stdio.h>
#include <stdlib.h>

// Function to heapify a subtree rooted at given index
void heapify(int arr[], int n, int i) {
  int largest = i; // Initialize the largest as the root
  int left = 2 * i + 1; // Left child
  int right = 2 * i + 2; // Right child

  // If left child is larger than the root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than the largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If the largest is not the root
  if (largest != i) {
    // Swap the largest element with the root
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// Function to perform heap sort
void heapsort(int arr[], int n) {
  // Build a max heap from the array
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Extract elements one by one from the heap
  for (int i = n - 1; i >= 0; i--) {
    // Move the current root to the end
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Call heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {23, 19, 45, 24, 46, 98, 12, 9, 5, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  heapsort(arr, n);

  printf("After sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

