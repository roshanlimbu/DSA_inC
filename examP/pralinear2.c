#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue{
  int front; 
  int rear;
  int data[MAX];
} Queue;


void initialize(Queue *queue){
  queue->rear=-1;
  queue->front=-1;
}


bool isEmpty(Queue *queue){
  return (queue->rear==-1 && queue->front==-1);
}
bool isFull(Queue *queue){
  return (queue->rear==MAX-1);
}

void enq(Queue *queue, int data){
  if(isFull(queue)){
    printf("Queeue overflow.\n");
    exit(EXIT_FAILURE);
  } else if(isEmpty(queue)) {
    queue->front=0;
  }
  queue->rear++;
  queue->data[queue->rear]=data;
}

int deq(Queue *queue){
  int deqedItem=0;

  if(isEmpty(queue)){
    printf("Queue underflow.");
    exit(EXIT_FAILURE);
  }
  deqedItem = queue->data[queue->front];

  if(queue->front== queue->rear){
    queue->front=-1;
    queue->rear=-1;
  } else {
    queue->front++;
  }

  return deqedItem;
}


void displyQ(Queue *queue){
  if(isEmpty(queue)){
    printf("no items in q.\n");
  } else{
    for(int i=queue->front; i<=queue->rear; i++){
      printf("%d\n", queue->data[i]);
    }
  }
printf("\n");
}

int main(){
  Queue queue;
  initialize(&queue);

  enq(&queue, 10);
  enq(&queue, 20);
  enq(&queue, 30);
  displyQ(&queue);
deq(&queue);

  displyQ(&queue);




  return 0;
}
