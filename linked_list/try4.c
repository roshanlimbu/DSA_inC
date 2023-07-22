//linkde list try 4

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;
void *createNode(int data){
  Node *newNode =  (Node *)malloc(sizeof(Node));
  newNode->data=data; 
  newNode->next=NULL;
  return newNode;
}
