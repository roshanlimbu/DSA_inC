#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct Stack {
  int data[MAX];
  int top;
} Stack;

void initialize(Stack *stack){
  stack->top= -1;
}
bool isEmpty(Stack *stack){
  return stack->top==-1;
}
bool isFull(Stack *stack){
  return stack->top==MAX-1;
}

void push(Stack *stack , int item){
  if(isFull(stack)){
    printf("Stack Overflow.");
  } else {
    stack->top++;
    stack->data[stack->top] = item;
    printf("%d was pushed to the stack.", item);
  }
}
void pop(Stack *stack ){
  int item;
  if(isEmpty(stack)){
    printf("Stack underflow.");
  } else {
    int item = stack->data[stack->top];
    stack->top--;
    printf("%d was removed from the stack.", item);
  }
}
void display(Stack *stack){
  if(isEmpty(stack)){
    printf("There is nothing to display.");
  } else {
    for (int i=stack->top; i>=0; i--){
      printf("%d\t", stack->data[i]);
    }
  }
  printf("\n");
}

int main(){
  int n;
  int choice;
  Stack stack;
  initialize(&stack);

  do {
    printf("Choose any options: \n");
    printf("\n1. Push ");
    printf("\n2. Pop ");
    printf("\n3. Display ");
    printf("\n4. Exit ");

    printf("\nEnter the choice: \n");
    scanf_s("%d", &choice);

    switch(choice){
      case 1:
        printf("\nEnter the data to be inserted: ");
        scanf_s("%d", &n);
        push(&stack, n);
        break;

      case 2: 
        pop(&stack);
        break;

      case 3: 
        display(&stack);
        break;

      case 4:
        printf("Exiting\n");
        break;

      default:
        printf("Invalid data.\n");
        break;
    }
  } while(choice!=4);

  return 0;
}
