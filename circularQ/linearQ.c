#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 10

// Structure to represent a linear queue
struct Queue {
  int data[MAX_SIZE];
  int front, rear;
};

// Initialize the queue
void initialize(struct Queue *queue) { queue->front = queue->rear = -1; }

// Check if the queue is empty
bool isEmpty(struct Queue *queue) { return (queue->front == -1); }

// Check if the queue is full
bool isFull(struct Queue *queue) {
  return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Queue is full. Enqueue operation failed.\n");
  } else {
    if (isEmpty(queue)) {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = item;
    printf("%d enqueued successfully.\n", item);
  }
}

// Dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Dequeue operation failed.\n");
    return -1;
  } else {
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
      queue->front = queue->rear =
          -1; // Reset the queue when the last element is dequeued
    } else {
      queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
  }
}

// Display the elements in the queue
void display(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
      printf("%d ", queue->data[i]);
      i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[queue->rear]);
  }
}

int main() {
  struct Queue queue;
  initialize(&queue);

  int choice, item;

  do {
    printf("\nSelect an option:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element to enqueue: ");
      scanf("%d", &item);
      enqueue(&queue, item);
      break;
    case 2:
      item = dequeue(&queue);
      if (item != -1) {
        printf("%d dequeued.\n", item);
      }
      break;
    case 3:
      display(&queue);
      break;
    case 4:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please select a valid option.\n");
    }
  } while (choice != 4);

  return 0;
}
