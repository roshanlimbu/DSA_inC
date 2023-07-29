#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10


typedef struct Queue{
  int front; 
  int rear;
  int data[MAX];
} Queue;


void initialize(Queue *queue){
  queue->front=-1;
  queue->rear=-1;
}


bool isEmpty(Queue *queue){
  return(queue->front ==-1 && queue->rear==-1) ;
}

bool isFull(Queue *queue){
  return(queue->rear==MAX-1) ;
}

void enqueue(Queue *queue, int data){
   if (isFull(queue)){
    printf("Queue overlow.\n");
    exit(EXIT_FAILURE);
  } else if(isEmpty(queue)) {
    queue->front=0;
  }
  queue->rear++;
  queue->data[queue->rear]=data;
}


int dequeue(Queue *queue){
  int removedItem=0;
  if(isEmpty(queue)){
    printf("Queue underflow");
    exit(EXIT_FAILURE);
  }
  removedItem = queue->data[queue->front];
  if(queue->front==queue->rear){
    queue->front=-1;
    queue->rear=-1;
  } else {
    queue->front++;
  }
  return removedItem;
}


void displayQ(Queue *queue){
  if(isEmpty(queue)){
    printf("The Q is empty. Nothing to show.");
    exit(EXIT_FAILURE);
  } else{
    for(int i=queue->front; i<=queue->rear; i++){
      printf("%d\n", queue->data[i]);
    }
  }
}
int main(){
  Queue queue;
  initialize(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  enqueue(&queue, 40);
  displayQ(&queue);

  int dequeuedEl = dequeue(&queue);
  printf("%d dequeued", dequeuedEl);
  displayQ(&queue);

}
