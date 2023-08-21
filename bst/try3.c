#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int info; 
    struct Node *left;
    struct Node *right;
    struct Node *father;
} Node;

Node *root = NULL;

Node *createNode(int info){
    Node *ptrnew = (Node *)malloc(sizeof(Node));
    if(ptrnew==NULL){
        printf("Memory allocation failed.\n");
        exit(0);
    }
    ptrnew->info=info;
    ptrnew->right=ptrnew->left=ptrnew->father=NULL;
    return ptrnew;
}
void bstInsert() {
    int n;
    Node* ptrnew, * parent = NULL, * curr = root;
    printf("Enter a number to be inserted: ");
    scanf("%d", &n);
    ptrnew = createNode(n);
    while (1) {
        if (curr == NULL) {
            if (root == NULL) {
                root = ptrnew;
                printf("%d inserted at the root.\n", ptrnew->info);
            }
            else {
                if (ptrnew->info < parent->info) {
                    parent->left = ptrnew;
                    printf("%d inserted to the left of %d.\n", ptrnew->info, parent->info);
                }
                else {
                    parent->right = ptrnew;
                    printf("%d inserted to the right of %d.\n", ptrnew->info, parent->info);
                }
                ptrnew->father = parent;
            }
            return;
        }
        else if (ptrnew->info < curr->info) {
            parent = curr;
            curr = curr->left;
        }
        else {
            parent = curr;
            curr = curr->right;
        }
    }
}


