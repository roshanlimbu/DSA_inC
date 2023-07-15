#include <stdbool.h>
#include <stdio.h>

#define MAX_CAPACITY 5

typedef struct {
  int items[MAX_CAPACITY];
  int top;
} Stack;

void initStack(Stack *stack) { stack->top = -1; }

bool isFull(Stack *stack) { return stack->top == MAX_CAPACITY - 1; }

bool isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int item) {
  if (isFull(stack)) {
    printf("Stack is full!\n");
    return;
  }

  stack->top++;
  stack->items[stack->top] = item;

  printf("Pushed item: %d\n", item);
}

void display(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty!\n");
    return;
  }

  printf("Stack:\n");
  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->items[i]);
  }
}

int main() {
  Stack stack;
  initStack(&stack);

  int item;

  printf("Enter the items to enqueue (enter -1 to stop):\n");

  while (true) {
    printf("Item: ");
    scanf("%d", &item);

    if (item == -1)
      break;

    push(&stack, item);
  }

  printf("\nEnqueued items:\n");
  display(&stack);

  return 0;
}
