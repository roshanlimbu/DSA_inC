#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to initialize the priority queue
void initializeQueue(PriorityQueue* queue) {
    queue->size = 0;
}

// Function to check if the priority queue is empty
int isQueueEmpty(const PriorityQueue* queue) {
    return queue->size == 0;
}

// Function to check if the priority queue is full
int isQueueFull(const PriorityQueue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to swap two elements in the priority queue
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the priority queue with a given priority
void enqueue(PriorityQueue* queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    int i = queue->size++; // Index to insert the new element
    queue->data[i] = element;

    // Restore the min-heap property by moving the new element up the tree
    while (i > 0 && queue->data[i] < queue->data[(i - 1) / 2]) {
        swap(&queue->data[i], &queue->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove and return the element with the highest priority from the priority queue
int dequeue(PriorityQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int removedElement = queue->data[0];
    queue->data[0] = queue->data[--queue->size];

    // Restore the min-heap property by moving the root element down the tree
    int i = 0;
    while (2 * i + 1 < queue->size) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int minChildIndex = leftChild;

        if (rightChild < queue->size && queue->data[rightChild] < queue->data[leftChild]) {
            minChildIndex = rightChild;
        }

        if (queue->data[i] <= queue->data[minChildIndex]) {
            break;
        }

        swap(&queue->data[i], &queue->data[minChildIndex]);
        i = minChildIndex;
    }

    return removedElement;
}

// Function to display the elements in the priority queue
void displayQueue(const PriorityQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 30);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    displayQueue(&queue); // Output: Priority Queue elements: 10 30 20

    int removedElement = dequeue(&queue);
    printf("Removed element: %d\n", removedElement); // Output: Removed element: 10

    displayQueue(&queue); // Output: Priority Queue elements: 20 30

    return 0;
}
