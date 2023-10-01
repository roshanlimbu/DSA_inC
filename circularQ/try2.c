#include <stdbool.h>
#include <stdio.h>
#define MAX 5
typedef struct queue {
  int data[MAX];
  int front;
  int rear;
} Queue;

void initilaize(Queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

bool isQFull(Queue *queue) { return (queue->rear + 1) % MAX == queue->front; }
bool isQEmp(Queue *queue) { return (queue->front == -1 && queue->rear == -1); }

void enQ(Queue *queue, int n) {
  if (isQEmp(queue)) {
    printf("\nQueue is empty.\n");
    return;
  } else {
    if (isQFull(queue)) {
      queue->rear = 0;
    }
  }
  queue->rear = (queue->rear + 1) % MAX;
  queue->data[queue->rear] = n;
  printf("\n%d inserted in the queue.\n", n);
}

