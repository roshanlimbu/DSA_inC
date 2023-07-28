#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;


Node *createNode(int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data= data;
  newNode->next = NULL;
  return newNode;
}

//func to insert at the beginning
void insertAtBegin(Node **head, int data){
  Node *newNode= createNode(data);
  newNode->next= *head;
  *head = newNode;
}

