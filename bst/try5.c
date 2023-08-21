#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int info;
    struct Node *left;
    struct Node *right;
    struct Node *father;
} Node;

Node *root = NULL; // initializing the root to null at first



// func to create newNode pointer

Node *createNode (int info){
    Node *ptrnew = (Node *)malloc(sizeof(Node));
    if(ptrnew==NULL){
        printf("Memory allocatin failed.");
        exit(0);
    } 
    ptrnew->info=info;
    ptrnew->father=NULL;
    ptrnew->left=NULL;
    ptrnew->right=NULL;
    return ptrnew;
}


void bstInsert(){
    int n;
    Node *ptrnew, *curr=root, *parent;
    printf("Enter the data to be inserted.\n");
    scanf("%d", &n);
    ptrnew=createNode(n);
    while(1){
        if(curr==NULL){
            if(root ==NULL){
                root = ptrnew;
                printf("%d inserted at the node of the tree.\n", ptrnew->info);
            } else {
                if(ptrnew->info<parent->info){
                    parent->left=ptrnew;
                    printf("%d inserted at left of the %d",ptrnew->info, parent->info);
                } else {
                    parent->right=ptrnew;
                    printf("%d inserted at right of the %d",ptrnew->info, parent->info);
                }
                ptrnew->father=parent;
            }
            return;
        } else if(ptrnew->info<curr->info){
            parent=curr;
            curr=curr->left;
        } else {
            parent=curr;
            curr=curr->right;
        }
    }
}
