#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
  int tempArr, i, j, flag, /* count =0 */;
  for (i = 0; i < n - 1; i++) {
    flag = 1;
    for (j = 0; j < n - i - 1; j++) {
    count++;
      if (arr[j] > arr[j + 1]) {
        tempArr = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tempArr;
        flag=0;
      }
    }
    if(flag==1) break;
  }
  // printf("\nNo. of count: %d ", count);
}

int main() {
  int arr[] = {3, 5, 1, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before Sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  bubbleSort(arr, n);

  printf("\nAfter Sorting:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

