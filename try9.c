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
