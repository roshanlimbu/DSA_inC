#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
  int data[MAX];
  int top;

}stack; 

void init(stack *s){
  s->top=-1;
}

bool isFull(stack * s){
  return s->top==MAX-1;

}
bool isEmpty( stack * s){
  return s->top==-1;

}
void push(stack* s){
  int item;
  if(isFull(s)){
    exit(EXIT_FAILURE);
  }
  else {
    printf("Enter the data to be inserted: \n");
    scanf_s("%d", &item);
    s->top++;
    s->data[s->top]=item;
    printf("\n%d was inserted:",item);
  }
}
void pop(stack *s){
  int a;
  if(isEmpty(s)){
    return;
  }
  else {
    a=s->data[s->top];
    s->top--;
    printf("Popped item:%d\n",a);
  }
}
void display(stack* s){
  if(isEmpty(s)){
    return;
  }else {
    for(int i=0;i<=s->top;i++){
      printf("%d\n",s->data[i]);
    }

  }
}

int main(){
  int x;
  stack s;
  init(&s);
  do{
    printf("\nEnter a choice:\n1. push\n2. pop\n3. display \n4. exit\n");
    scanf_s("%d\n",&x);
    switch (x) {
      case 1:
        push(&s);
        break;
      case 2:
        pop(&s);
        break;
      case 3:
        display(&s);
        break;
      case 4:
        return 0;
        break;
    }

  } while(x!=4);
  return 0;

}
