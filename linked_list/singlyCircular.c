#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly circular linked list
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the front of the list
void insertAtFront(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    newNode->next = newNode; // Point to itself for circularity
    *head = newNode;
  } else {
    newNode->next = (*head)->next;
    (*head)->next = newNode;
  }
}

// Function to insert a node at the end of the list
void insertAtLast(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    newNode->next = newNode; // Point to itself for circularity
    *head = newNode;
  } else {
    newNode->next = (*head)->next;
    (*head)->next = newNode;
    *head = newNode;
  }
}

// Function to insert a node after a given node with a specific data
void insertAfter(Node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }
  Node *newNode = createNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

// Function to insert a node before a given node with a specific data
void insertBefore(Node **head, int data, int key) {
  if (*head == NULL) {
    printf("List is empty, cannot insert before\n");
    return;
  }
  Node *newNode = createNode(data);
  if ((*head)->data == key) {
    newNode->next = (*head)->next;
    (*head)->next = newNode;
  } else {
    Node *current = *head;
    while (current->next != *head && current->next->data != key) {
      current = current->next;
    }
    if (current->next->data == key) {
      newNode->next = current->next;
      current->next = newNode;
    } else {
      printf("Key not found in the list\n");
    }
  }
}

// Function to remove a node with a specific data from the list
void removeFromList(Node **head, int key) {
  if (*head == NULL) {
    printf("List is empty, cannot remove\n");
    return;
  }
  Node *current = *head;
  Node *prev = NULL;

  if (current->data == key) {
    while (current->next != *head) {
      current = current->next;
    }
    current->next = (*head)->next;
    free(*head);
    *head = current->next;
    return;
  }

  while (current->next != *head && current->data != key) {
    prev = current;
    current = current->next;
  }

  if (current->data == key) {
    prev->next = current->next;
    free(current);
  } else {
    printf("Key not found in the list\n");
  }
}

// Function to display the singly circular linked list
void displayList(Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *current = head;
  printf("Linked List: ");
  do {
    printf("%d -> ", current->data);
    current = current->next;
  } while (current != head);
  printf("... (Circular)\n");
}

// Function to free the memory and exit the program
void exitProgram(Node *head) {
  Node *current = head;
  if (current == NULL) {
    exit(0);
  }
  do {
    Node *temp = current;
    current = current->next;
    free(temp);
  } while (current != head);
  exit(0);
}

int main() {
  Node *head = NULL;
  int choice, data, key;

  while (1) {
    printf("\nSingly Circular Linked List Operations:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Last\n");
    printf("3. Insert After\n");
    printf("4. Insert Before\n");
    printf("5. Remove from List\n");
    printf("6. Display List\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to insert at the front: ");
      scanf("%d", &data);
      insertAtFront(&head, data);
      break;
    case 2:
      printf("Enter data to insert at the last: ");
      scanf("%d", &data);
      insertAtLast(&head, data);
      break;
    case 3:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter data after which to insert: ");
      scanf("%d", &key);
      insertAfter(head, data);
      break;
    case 4:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      printf("Enter data before which to insert: ");
      scanf("%d", &key);
      insertBefore(&head, data, key);
      break;
    case 5:
      printf("Enter data to remove: ");
      scanf("%d", &data);
      removeFromList(&head, data);
      break;
    case 6:
      displayList(head);
      break;
    case 7:
      exitProgram(head);
    default:
      printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}
