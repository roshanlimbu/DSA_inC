#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int info;
  struct node* left;
  struct node* right;
  struct node* father;
} Node;

Node* root = NULL;

Node* createNode(int info) {
  Node* ptrnew = (Node*)malloc(sizeof(Node));
  if (ptrnew == NULL) {
    printf("Memory allocation failed.");
    exit(EXIT_FAILURE);
  }
  ptrnew->info = info;
  ptrnew->father = ptrnew->left = ptrnew->right = NULL;
  return ptrnew;
}

void freeMemory(Node* r) {
  if (r != NULL) {
    freeMemory(r->left);
    freeMemory(r->right);
    free(r);
  }
}

void bstInsert(int n) {
  Node* ptrnew = createNode(n);
  Node* parent = NULL;
  Node* curr = root;
  
  while (curr != NULL) {
    parent = curr;
    if (n < curr->info)
      curr = curr->left;
    else
      curr = curr->right;
  }

  if (parent == NULL) {
    root = ptrnew;
    printf("%d inserted at the root.\n", ptrnew->info);
  } else {
    if (n < parent->info) {
      parent->left = ptrnew;
      printf("%d inserted to the left of %d.\n", ptrnew->info, parent->info);
    } else {
      parent->right = ptrnew;
      printf("%d inserted to the right of %d.\n", ptrnew->info, parent->info);
    }
    ptrnew->father = parent;
  }
}

bool bstSearch(Node* r, int target) {
  if (r == NULL)
    return false;
  if (r->info == target)
    return true;
  if (target < r->info)
    return bstSearch(r->left, target);
  else
    return bstSearch(r->right, target);
}

Node* getMinNode(Node* r) {
  while (r->left != NULL)
    r = r->left;
  return r;
}

Node* bstRemove(Node* r, int d) {
  if (r == NULL) {
    printf("%d does not exist in the tree.\n", d);
    return r;
  }

  if (d < r->info)
    r->left = bstRemove(r->left, d);
  else if (d > r->info)
    r->right = bstRemove(r->right, d);
  else {
    if (r->left == NULL) {
      Node* temp = r->right;
      free(r);
      return temp;
    } else if (r->right == NULL) {
      Node* temp = r->left;
      free(r);
      return temp;
    }

    Node* temp = getMinNode(r->right);
    r->info = temp->info;
    r->right = bstRemove(r->right, temp->info);
  }
  return r;
}

void inorder(Node* r) {
  if (r != NULL) {
    inorder(r->left);
    printf("%d ", r->info);
    inorder(r->right);
  }
}

void preorder(Node* r) {
  if (r != NULL) {
    printf("%d ", r->info);
    preorder(r->left);
    preorder(r->right);
  }
}

void postorder(Node* r) {
  if (r != NULL) {
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->info);
  }
}

int main() {
  char ch;
  int data;
  while (1) {
    printf("Select your option:\n1. Insert\n2. Remove\n3. Inorder Visit\n");
    printf("4. Preorder Visit\n5. Postorder Visit\n6. Search\n7. Exit\n");
    fflush(stdin);
    ch = getchar();
    system("clear"); // Use "cls" instead of "clear" on Windows.

    switch (ch) {
      case '1':
        printf("Enter a number to be inserted: ");
        scanf("%d", &data);
        bstInsert(data);
        break;
      case '2':
        printf("Enter a number to be removed: ");
        scanf("%d", &data);
        root = bstRemove(root, data);
        break;
      case '3':
        inorder(root);
        printf("\n");
        break;
      case '4':
        preorder(root);
        printf("\n");
        break;
      case '5':
        postorder(root);
        printf("\n");
        break;
      case '6':
        printf("Enter a number to be searched: ");
        scanf("%d", &data);
        if (bstSearch(root, data))
          printf("%d found in the tree.\n", data);
        else
          printf("%d does not exist in the tree.\n", data);
        break;
      case '7':
        freeMemory(root);
        exit(EXIT_SUCCESS);
      default:
        printf("Invalid option. Please try again.\n");
    }
    
    while(getchar() != '\n');  // Clear input buffer
  }
  
  return 0;
}
