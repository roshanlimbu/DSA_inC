#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Maximum number of elements in the circular queue

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
bool isQueueEmpty(const CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
bool isQueueFull(const CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(CircularQueue* queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    } else if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int removedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Only one element in the queue, reset front and rear to -1
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return removedElement;
}

// Function to get the front element of the circular queue without dequeuing it
int front(const CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot get front element.\n");
        return -1;
    }

    return queue->data[queue->front];
}

// Function to display the elements in the circular queue
void displayQueue(const CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    displayQueue(&queue); // Output: Circular Queue elements: 10 20 30

    int frontElement = front(&queue);
    printf("Front element: %d\n", frontElement); // Output: Front element: 10

    int removedElement = dequeue(&queue);
    printf("Removed element: %d\n", removedElement); // Output: Removed element: 10

    displayQueue(&queue); // Output: Circular Queue elements: 20 30

    return 0;
}
