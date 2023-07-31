#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10

typedef struct Stack{
  int data[MAX];
  int top;
} Stack;

void initialize(Stack *stack){
  stack->top=-1;
}
bool isEmpty(Stack *stack){
  return stack->top==-1;
}
bool isFull(Stack *stack){
  return stack->top == MAX-1;
}
void push(Stack *stack, int item){
  if(isFull(stack)){
    printf("Stack overflow. Can't add new items.\n");
    exit(EXIT_FAILURE);
  } else {
    stack->top++;
    stack->data[stack->top]=item;
  }
}
void pop(Stack *stack){
  int data;
  if(isEmpty(stack)){
    printf("Stack underflow.");
    exit(EXIT_FAILURE);
  } else {
    data=stack->data[stack->top];
    stack->top--;
  }
}
void display(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack underlflow.");
    exit(EXIT_FAILURE);
  } else {
    for(int i=stack->top; i>=0; i--){
      printf("%d\n", stack->data[i]);
    }
  }
}
int main(){
  Stack stack;
  initialize(&stack);
  int choice;
  int n=0; 
  do {
    printf("Enter the choice: \t \n1. Push \n2. Pop \n3. Display \n4. Exit\n");
    scanf_s("%d\n",&choice );
    switch (choice) {
      case 1: 
        printf("\nEnter the data to push \n");
        scanf_s("%d", &n);
        push(&stack,  n);
        break;
      case 2: 
        pop(&stack);
        break;
      case 3:
        display(&stack);
        break;

      case 4: 
        exit(0);
        break;

      default:
        printf("Invalid input.\n");
        break;
    }
  }while (choice!=4);



  return 0;
}


