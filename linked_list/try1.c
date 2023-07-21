#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
  int data;
  struct Node *next;
} Node;
// Function to create a new node and return a pointer to it
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Function to display the linked list
void displayList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

int main() {
  Node *head = NULL;

  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtBeginning(&head, 5);
  insertAtEnd(&head, 30);

  printf("Linked list elements: ");
  displayList(head);

  freeList(head);

  return 0;
}
