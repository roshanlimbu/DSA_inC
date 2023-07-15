#include <stdbool.h>
#include <stdio.h>

#define MAX 5

typedef struct {
  int item[MAX];
  int top;
} Stack;

void initStack(Stack *stack) { stack->top = -1; }

bool isFull(Stack *stack){
  return stack->top== MAX-1;
}
bool isEmpty(Stack *stack){
  return stack->top== -1;
}
void push(Stack *stack , int item){
  if(isFull(stack)){
    printf("\nStack overflow. \n");
    return;
  } else {
    stack->top++;
    stack->item[stack->top]=item;
    printf("\nItem Pushed %d \n", item);
  }
}
void display(Stack *stack){
  if(isEmpty(stack)){
    printf("\nStack is empty. \n ");
    return; 
  } else {
  for(int i=stack->top; i>=0; i--){
      printf("\n%d", stack->item[i]);
    }
  }
}
int main(){
  Stack stack;
  initStack(&stack);

  int item;

  printf("Enter the items you want to enqueue: -1 to stop : \n ");

  while(true){
    printf("Item: ");
    scanf("%d", &item);
    if (item==-1) {
      break; 
    }
    push(&stack, item);
  }
  printf("\n Enqueued items: \n");
  display(&stack);
  return 0;
}
