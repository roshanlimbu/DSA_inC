#include <stdio.h>
#define MAX 20
int getDigitCount(int n){
  int count =0;
  while (n>0) {
    n=n/10;
    count++;
  }
  return count;
}
int getMaxDigitCont(int arr[], int n){
  int max = arr[0], i;
  for(i=1; i<n; i++){
    if(max<arr[i]){
      max = arr[i];
      // max holds the highest nuber, so count its digits
    }
  }
  return getDigitCount(max);
}

void countsort (int arr[], int n, int pos){
  int temp[MAX];
  int count[10]={0};
  int i;
  for(i=0; i<n; i++){
    count [(arr[i]/pos)%10]++;
  }
  for(i=1; i<10; i++){
    count [i]+=count[i-1];
  }
  for(i=n-1; i>=0; i--){
    temp[--count[(arr[i]/pos)%10]]=arr[i];
  }
  for(i=0; i<n; i++){
    arr[i]=temp[i];
  }
}

int main(){
  int arr[]={23, 19, 45, 24, 46, 98, 12, 9, 5, 1};
  int i;
  printf("Before sorting..........");
  for(i=0; i<10; i++){
    printf("%d ", arr[i]);
  }; 

  countsort(arr, 10);
  printf("After sorting..........");
  for(i=0; i<10; i++){
    printf("%d ", arr[i]);
  }; 

  return 0;
}

