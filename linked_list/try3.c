#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// defining the structure for the nodes 
typedef struct Node {
  int data;
  struct Node *next;
} Node;


// func to create the new node using malloc
Node *createNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data=data; // this puts the new data to the new node
  newNode->next=NULL; // this puts the new node pointer to null as it would be at last
  return newNode;
} 


// func to insert a node at the beginning of the list
void insertNode(Node **head, int data){
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}


void removeNode(Node **head, int data) {
  Node *current = *head;
  Node *prev = NULL;

  // If the node to be removed is the head node
  if (current != NULL && current->data == data) {
    *head = current->next;
    free(current);
    return;
  }

  // Search for the node to be removed
  while (current != NULL && current->data != data) {
    prev = current;
    current = current->next;
  }

  // If the node is not found
  if (current == NULL) {
    printf("Node with data %d not found.\n", data);
    return;
  }

  // Remove the node from the list
  prev->next = current->next;

  // Check if the node to be removed is the last node
  if (current->next == NULL) {
    // Update the head pointer if the last node is removed
    *head = prev;
  }

  free(current);
}

// void removeNode(Node **head, int data) {
//   Node *current = *head;
//   Node *prev = NULL;

//   // If the node to be removed is the head node
//   if (current != NULL && current->data == data) {
//     *head = current->next;
//     free(current);
//     return;
//   }

//   // Search for the node to be removed
//   while (current != NULL && current->data != data) {
//     prev = current;
//     current = current->next;
//   }

//   // If the node is not found
//   if (current == NULL) {
//     printf("Node with data %d not found.\n", data);
//     return;
//   }

//   // Remove the node from the list
//   prev->next = current->next;
//   free(current);
// }

// Function to display the linked list
void displayList(Node *head) {
  Node *current = head;
  if (current == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Linked List: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
