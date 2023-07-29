#include <stdio.h>
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
  return (stack->top==-1);
}

bool isFull(Stack *stack){
  return (stack->top==MAX-1);
}

void push (Stack *stack){
  int n;
  if(isFull(stack)){
    printf("Stack overflow.\n");
  } else{
    stack->top++;
    printf("Enter the data to be inserted: \n" );
    scanf_s("%d", &n);
    stack->data[stack->top]=n;
    printf("%d was pushed to the stack.", n);
  }
}
void pop(Stack *stack){
  int data=0;
  if(isEmpty(stack)){
    printf("Stack underflow.");
  } else{
    data = stack->data[stack->top];
    printf("%d was popped" , data);
    stack->top--;
  }
}


void display(Stack *stack){
  if(isEmpty(stack)){
    printf("Stack underflow");
  } else {
    for(int i=stack->top; i>=0; i--){
      printf("%d\n", stack->data[i]);
    }
  }
  printf("\n");
}


int main(){
  Stack stack;
  initialize(&stack);
  int choice;
  do {
    printf("Enter the choice:\n") ;
    printf("1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT") ;
    scanf_s("%d", &choice);
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
        exit(0);
        break;      
      default:
        printf("Invalid option");
        break;
    }

  }while (choice!=4);
  return 0;
}
