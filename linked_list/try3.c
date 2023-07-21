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

