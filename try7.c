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

