#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct DoublyLinkedList {
    Node* head;
};

typedef struct DoublyLinkedList DoublyLinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the list
void insertAtFront(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node after a specified element
void insertAfter(DoublyLinkedList* list, int key, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        printf("Error: Doubly Linked List is empty.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Key not found in the Doubly Linked List.\n");
        return;
    }
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to insert a node before a specified element
void insertBefore(DoublyLinkedList* list, int key, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        printf("Error: Doubly Linked List is empty.\n");
        return;
    }
    if (list->head->data == key) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Key not found in the Doubly Linked List.\n");
        return;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}

// Function to remove a node with a specified key
void removeFromList(DoublyLinkedList* list, int key) {
    if (list->head == NULL) {
        printf("Error: Doubly Linked List is empty.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Key not found in the Doubly Linked List.\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    printf("Element with key %d removed from the list.\n", key);
}

// Function to display the Doubly Linked List
void displayList(DoublyLinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList list;
    list.head = NULL;

    int choice, data, key;
    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After an Item\n");
        printf("4. Insert Before an Item\n");
        printf("5. Remove an Item\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtFront(&list, data);
                printf("Element inserted at the front.\n");
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                printf("Element inserted at the end.\n");
                break;
            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAfter(&list, key, data);
                break;
            case 4:
                printf("Enter the key before which to insert: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBefore(&list, key, data);
                break;
            case 5:
                printf("Enter the key to remove: ");
                scanf("%d", &key);
                removeFromList(&list, key);
                break;
            case 6:
                displayList(&list);
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}
