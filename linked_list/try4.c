//linkde list try 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;
void *createNode(int data){
  Node *newNode =  (Node *)malloc(sizeof(Node)); // allocating memory for a new node using `malloc` func, which dynamically allocates  memeory on the heap
  newNode->data=data; // initializes the `data` field of the newly created node with the value provided as the function argument.
  newNode->next=NULL; // sets the `next` pointer of the node to `NULL`, assuming it's the last node in the list or will be connected to another node later
  return newNode;// Fianlly, it returns the pointer to the newly created node
}
