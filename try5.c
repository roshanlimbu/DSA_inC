#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 20
typedef struct{
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
  return stack->top==MAX-1;
}
void push(Stack *stack ){
  int n;
  if(isFull(stack)){
    printf("The stack is full");
  } else {
   printf("Enter the item") ;
    scanf_s("%d", &n);
    stack->top++;
    stack->data[stack->top]= n;
    printf("%d was pushed to the stack. " , n );
  }
}
void pop(Stack *stack){
  int item;
  if(isEmpty(stack)){
    printf("The stack is empty.\n");
  } else {
    item = stack->data[stack->top];
    stack->top--;
    printf("%d was removed from the stack.\n", item);
  }
}
void display(Stack *stack){
  if(isEmpty(stack)){
    printf("The stack is empty.\n");
  } else{
    printf("Stack items:\n");
    for (int i= stack->top; i>=0; i--){
      printf("%d", stack->data[i]);
    }
  }
  printf("\n");
}


int main(){
  Stack stack;
  initialize(&stack);
  int choice;
  do{
    printf("\nChoose the options:\n");
    printf("1. Push\n ");
    printf("2. Pop \n");
    printf("3. Display \n");
    printf("4. Exit \n");
    printf("Enter the choice: \n");
    scanf_s("%d", &choice);
    switch (choice) {
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
        printf("Exiting program");
        break;
      default:
        printf("Invalid input.");
    }
  } while (choice!=4);
  return 0;
}


