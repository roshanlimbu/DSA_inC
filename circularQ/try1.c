#include <stdio.h>
#include <stdbool.h>
#define MAX 5


typedef struct queue{
  int data[MAX];
  int front;
  int rear;
} Queue;


void initialize(Queue *queue){
  queue->front=-1;
  queue->rear=-1;
}

bool isQEmpty(Queue *queue){
  return (queue->front==-1);
}

bool isQFull(Queue *queue){
  return (queue->rear+1) % MAX == queue->front; // idk what's going here
}

void enQ(Queue *queue, int n){
  if(isQFull(queue)){
    printf("Queue is full. \n");
    return;
  } else {
    if(isQEmpty(queue)){
      queue->rear=0;
    }
  }
  queue->rear = (queue->rear +1) % MAX;
  queue->data[queue->rear] = n;
  printf("\n%d inserted in the queue.\n" , n);
}


int deQ(Queue *queue){
  if(isQEmpty(queue)){
    printf("Queue is empty. \n");
    return -1;
  }
  int n = queue->data[queue->front];
  if(queue->front==queue->rear){
    queue->front=-1;
    queue->rear=-1;
  } else {
    queue->front=(queue->front+1)% MAX;
  }
  return n;
}

int main(){
  Queue queue;
  initialize(&queue);
  int n;
  int choice;
  do {
    printf("Enter the choice: \n");
    printf("1. Enqueue \n2. Dequeue \n3. Remove \n4. Display \n5. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the number to enqueue: \n");
        scanf("%d", &n);

        enQ(&queue,  n);


    }
  } while(choice!=5);

  return 0;
}
