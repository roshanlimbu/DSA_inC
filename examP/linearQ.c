#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Queue{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isQueueEmpty(const Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
bool isQueueFull(const Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue (insert) an element into the queue
void enqueue(Queue* queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        exit(EXIT_FAILURE);
    } else if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = element;
}

// Function to dequeue (remove) an element from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        exit(EXIT_FAILURE);
    }

    int removedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Only one element in the queue, reset front and rear to -1
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    return removedElement;
}

// Function to get the front element of the queue without dequeuing it
int front(const Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot get front element.\n");
        exit(EXIT_FAILURE);
    }

    return queue->data[queue->front];
}

// Function to display the elements in the queue
void displayQueue(const Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    displayQueue(&queue); // Output: Queue elements: 10 20 30

    int frontElement = front(&queue);
    printf("Front element: %d\n", frontElement); // Output: Front element: 10

    int removedElement = dequeue(&queue);
    printf("Removed element: %d\n", removedElement); // Output: Removed element: 10

    displayQueue(&queue); // Output: Queue elements: 20 30

    return 0;
}
