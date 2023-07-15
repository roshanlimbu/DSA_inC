#include <stdbool.h>
#include <stdio.h>

#define MAX 5

typedef struct {
  int item[MAX];
  int top;
} Stack;

// initialize the stack
void initStack(Stack *stack) { stack->top = -1; }

bool isFull(Stack *stack) { return stack->top == MAX - 1; }
bool isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int item) {
  if (isFull(stack)) {
    printf("\nStack overflow.");
    return;
  } else {
    stack->item[++stack->top] = item;
    printf("\nPushed item: %d \n", item);
  }
}
void display(Stack *stack) {
  if (isEmpty(stack)) {
    printf("\nStack underflow.");
    return;
  } else {
    printf("Stack items: \n");
    for (int i = stack->top; i >= 0; i--) {
      printf("%d\n", stack->item[i]);
    }
  }
}
int main() {
  Stack stack;
  initStack(&stack);
  int item;
  printf("Enter the items you want to enqueue: type -1 if you want to stop\n");
  while (true) {
    printf("Item: ");
    scanf_s("%d", &item);
    if (item == -1) {
      break;
    }
  push(&stack,item);
  }
  printf("\nEnqueued items: \n ");
  display(&stack);
  return 0;
}
