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

