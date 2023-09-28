#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
  int data[MAX];
  int top;
} Stack;

void initialize (Stack *stack){
  stack->top =-1;
}
bool isEmpty(Stack *stack){
  return stack->top ==-1;
}
bool isFull(Stack *stack){
  return stack->top == MAX-1;
}
void push(Stack *stack){
  int n;
  if(isFull(stack)){
    printf("Stack overflow.\n");
  } else{
    printf("Enter the item you want to insert: ");
    scanf("%d", &n);
    stack->top++;
    stack->data[stack->top]=n;
    printf("The item %d was pushed. \n", n);
  }
};
void pop(Stack *stack){
  int item;
  if(isEmpty(stack)){
    printf("Stack underflow: \n");
  } else {
    item = stack->data[stack->top];
    stack->top--;
    printf("%d was remove from the stack.\n", item);
  }
};
void display(Stack *stack){
  if(isEmpty(stack)){
    printf("The stack is empty");
  } else {
    printf("Stack elements: ");
    for(int i=stack->top; i>=0; i--){
      printf("%d", stack->data[i]);
    }
    printf("\n");
  }
};


int main(){
  Stack stack;
  initialize(&stack);
  int choice;
  do{
    printf("Stack operations: ");
    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\nEnter the choice:");
    scanf("%d", &choice);
    
    switch(choice){
      case 1: 
      push(&stack);
      break;
      case 2: 
      pop(&stack);
      break;
      case 3: 
      display(&stack);
      break;
      case 4: 
      printf("Exiting the program.");
      break;
        default:
      printf("Invalid data.");
    }
  } while(choice!=4);
  return 0;
}
