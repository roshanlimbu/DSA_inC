#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct stack {
  int data[MAX];
  int top;
} Sp;

void initialize(Sp *stack){
  stack->top=-1;
}
bool isEmpty(Sp *stack){
  return stack->top==-1;
}

bool isFull(Sp *stack){
  return stack->top==MAX-1;
}

void push(Sp *stack, int item){
  if(isFull(stack)){
    printf("Stack overflow.\n");
  } else {
    stack->top++;
    stack->data[stack->top]= item;
    printf("%d was puhsed to stack.", item);
  }
}
void pop(Sp *stack){
  int item;
  if(isEmpty(stack)){
    printf("Stack underflow.\n");
  } else{
    int item = stack->data[stack->top];
    stack->top--;
    printf("The %d was removed form the stack.\n", item);
  }
}


void display(Sp *stack){
  if(isEmpty(stack)){
    printf("The stack is empty. Nothing to show.\n");
  } else {
    for(int i=stack->top; i>=0; i--){
      printf("%d\n" , stack->data[i]);
    }
  }
}


int main(){
  int n;
  Sp stack;
  initialize(&stack);
  int choice;
  do {
    printf("\nOptions:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter the choice:");
    scanf_s("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the item to push: \n");
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
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice.");
        break;
    }

  }while (choice!=4);


  return 0;
}
