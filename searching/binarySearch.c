#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high,  int key){
  int mid ;
  // For using loops
  // while(low<=high){
  //   mid=(low+high)/2;
  //   if(arr[mid]==key){
  //     return mid;
  //   } else if(arr[mid]>key){
  //     high=mid-1;
  //   } else {
  //     low=mid++;
  //   }
  // }


  while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==key){
      return mid;
    } else if(arr[mid]>key){
      return binarySearch(arr, low,  high,  key);
    } else{
      return binarySearch(arr, mid+1, high, key);
    }
  }
  return -1;

}

int main () {
  int arr[] = {12, 14,  15, 19, 22, 34, 37, 42, 50};
  int key, found;
  printf("Enter the key you want to find: ");
  scanf("%d", &key);
  found=binarySearch(arr,0,  10, key);
  if(found==-1){
    printf("%d does not exist in the array.", key);
  } else {
    printf("%d is found in the array at position %d", key, found+1);
  }
  return 0;
}
