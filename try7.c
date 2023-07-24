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
