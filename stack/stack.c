#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10
typedef struct stack {
  int top;
  int data[MAX];
} Stack;


void initialize(Stack *stack){
  stack->top=-1;
}

bool isEmpty(Stack *stack){
  return (stack->top==-1);
}
bool isFull(Stack *stack){
  return (stack->top==MAX-1);
}

void push(Stack *stack){
  int n;
  if(isFull(stack)){
    printf("Stack overflow");
  } else {
    printf("Enter the data to be inserted: ");
    scanf("%d", &n);
  }
  stack->top++;
  stack->data[stack->top]=n;
  printf("%d inserted at the top of stack.\n", n);

}



int main(){
  Stack stack;
  initialize(&stack);
  int choice;

  do{
    printf("Enter the choice:\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        push(&stack);
        break;
    }
  } while(choice!=4);
  return 0;
}
