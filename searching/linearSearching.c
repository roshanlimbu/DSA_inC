#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int key){
  int i;
  for(i=0; i<n; i++){
    if(arr[i]==key){
      return 1;
    } else {
      return -1;
    }
  }
  return 0;
}


int main(){
  int arr[] = {12, 14, 56, 15, 19, 22, 34, 17, 12, 10};
  int key, found;
  printf("Enter the key you want to find: ");
  scanf("%d", &key);
  found=linearSearch(arr, 10, key);
  if(found==-1){
    printf("%d does not exist in the array.", key);
  } else {
    printf("%d is found in the array at position %d", key, key+1);
  }
  return 0;
}
