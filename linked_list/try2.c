#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;


// Pointer func to create a new node 
Node *createNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data= data;
  newNode->next= NULL;
  return newNode;
}

// func to insert at the beginning
void insertAtBeginning(Node **head, int data){
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}
