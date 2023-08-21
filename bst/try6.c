#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int info; 
    struct Node *left;
    struct Node *right;
    struct Node *father;
} Node ;

Node * root = NULL; // initializing the root node


// func to create a new node
Node *createNode(int info){
    Node *ptrnew = (Node *)malloc(sizeof(Node));
    if(ptrnew==NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    ptrnew->info=info;
    ptrnew->left=ptrnew->right=ptrnew->father=NULL;
    return ptrnew;
}

void bstInsert(){
    int info;
    Node *ptrnew, *curr = NULL, *parent =root;
    printf("Enter the data to insert: ");
    scanf("%d", &info);
    ptrnew=createNode(info);
    
    while(1){
        if(curr==NULL){
            if(root==NULL){
                root = ptrnew;
                printf("%d inserted at the root. ", ptrnew->info);
            } else {
                if(ptrnew->info<parent->info){
                    parent->left=ptrnew;
                    printf("%d inserted at the left of %d. " ,ptrnew->info, parent->info);
                } else {
                    parent->right=ptrnew;
                    printf("%d inserted at the left of %d. " ,ptrnew->info, parent->info);
                }
                ptrnew->father=parent;
            }
            return;
        } else if(ptrnew->info<curr->info){
            parent = curr;
            curr = curr->left;
        } else {
            parent=curr;
            curr=curr->right;
        }
    }
}
void bstRemove(Node *r, int d){

}

bool isLeft(Node *p){
    return (p->father)->left==p;
}
void getMinNode(Node *r){
    while(r->left!=NULL){
        r=r->left;
    }
}















