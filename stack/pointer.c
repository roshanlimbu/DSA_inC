#include <stdio.h>
#include <conio.h>
int main(){
  int x=10; // A variable
  int y=20;
  int *ptr1; // Pointer variable holds the address of another variable 
  int *ptr2;
  ptr1 = &x; // Assigning the address of x to the pointer
  ptr2 = &y;
  printf("Memory address of x is %d and memory address of y is: %d ", &x , &y );
}
