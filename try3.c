#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
  int items[MAX];
  int top;
} sp ;

void initStack(sp *stack){
  stack->top=-1;
}
bool isFull(sp *stack){
  return stack->top=-1;
}
