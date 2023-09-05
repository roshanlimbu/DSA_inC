#include <stdio.h>

void shellsort(int arr[], int n){
  int gap, i, j, temp;
  for(gap=n/2; gap>0; gap/=2){
    for(i=gap; i<n; i++){
      temp=arr[i];
      /* for(j=i; j>=gap && arr[j-gap]>temp; j=j-gap){ */
      for(j=i-gap; j>=gap && arr[j-gap]>temp; j=j-gap){
        /* arr[j] = arr[j-gap]; */
        /* arr[j] = temp; */
        arr[j+gap] = arr[j];
      }
      arr[j+gap] = temp; // remove if you uncomment code above
    }
  }
}

int main(){
  int arr [] = {7, 9, 1, 4, 9, 3, 13, 23, 18, 19};
  printf("Before sorting...........");
  for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d " , arr[i]);
  }
  shellsort(arr, sizeof(arr)/sizeof(int));
  printf("\n After sorting............");
  for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    printf("%d " , arr[i]);
  }
  return 0;
}


