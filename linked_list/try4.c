#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;


Node *createNode(int data){
  Node *newNode= (Node *)malloc(sizeof(Node));
  newNode->data= data;
  newNode->next=NULL;
  return newNode;
}

//func to insert at the beginning
void insertAtBeginning(Node **head, int data){
  Node *newNode = createNode(data);
  newNode->next=*head;
  *head= newNode;
}
void insertAtEnd(Node **head, int data){
  Node *newNode = createNode(data);
  if(*head == NULL){
    *head = newNode;
    return;
  }
  Node *current=*head;
  while(current->next!=NULL){
    current=current->next;
  }
  current->next = newNode;
}
void displayList(Node *head){
  Node *current = head;
  while(current!=NULL){
    printf("%d->", current->data);
    current=current->next;
  }
  printf("NULL\n");
}

