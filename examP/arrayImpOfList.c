#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* data;       // Pointer to the array storing list elements
    int size;        // Current number of elements in the list
    int capacity;    // Maximum capacity of the list
} ArrayList;

// Function to initialize the list
void initializeList(ArrayList* list) {
    list->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (list->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

// Function to check if the list is empty
int isListEmpty(const ArrayList* list) {
    return list->size == 0;
}

// Function to get the size of the list
int getListSize(const ArrayList* list) {
    return list->size;
}

// Function to add an element to the end of the list
void append(ArrayList* list, int element) {
    if (list->size == list->capacity) {
        // If the array is full, increase its capacity
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    list->data[list->size++] = element;
}

// Function to get the element at a specific index
int getElementAt(const ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index.\n");
        exit(EXIT_FAILURE);
    }

    return list->data[index];
}

// Function to remove the element at a specific index
void removeElementAt(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;

    // If the size becomes less than half of the capacity, reduce the capacity
    if (list->size <= list->capacity / 2) {
        list->capacity /= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to free the memory occupied by the list
void destroyList(ArrayList* list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

int main() {
    ArrayList list;
    initializeList(&list);

    append(&list, 10);
    append(&list, 20);
    append(&list, 30);

    printf("List size: %d\n", getListSize(&list)); // Output: List size: 3
    printf("Element at index 1: %d\n", getElementAt(&list, 1)); // Output: Element at index 1: 20

    removeElementAt(&list, 1);
    printf("List size after removal: %d\n", getListSize(&list)); // Output: List size after removal: 2

    destroyList(&list);

    return 0;
}
