#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int info;
    struct Node *left;
    struct Node *right;
    struct Node *father;
} Node;

Node *root = NULL;


Node *createNode (int info){
    Node *ptrnew = (Node *)malloc(sizeof(Node));
    if(ptrnew==NULL){
        printf("Memory allocation failed.");
        exit(1);
    }
    ptrnew->info=info;
    ptrnew->left=NULL;
    ptrnew->right=NULL;
    ptrnew->father=NULL;
    return ptrnew;
}


void bstInsert(){
    int info; 
    Node *ptrnew, *curr=root, *parent =NULL;
    printf("Enter the data to be inserted: ");
    scanf("%d" , &info);

    ptrnew=createNode(info);
    if(curr==NULL){
        if(root==NULL){
            root=ptrnew;
            printf("%d inserted at the root position.\n", ptrnew->info);
        } else {
            if(ptrnew->info<parent->info){
                parent->left=ptrnew;
                printf("%d inserted at left of %d\n", ptrnew->info, parent->info);
            } else {
                parent->right=ptrnew;
                printf("%d inserted at left of %d\n", ptrnew->info, parent->info);
            }
            ptrnew->father=parent;
        }    
        return;
    } else if(ptrnew->info<curr->info){
        parent = curr;
        curr=curr->left;
   } else {
        parent = curr;
        curr=curr->right;
    }
}

bool isLeft(Node *p){
    return (p->father)->left==p;
}

void getMinNode (Node *r){
    while (r->left!=NULL) {
        r=r->left; 
    }
}
void inOrder(Node *r){
    if(r!=NULL){
        inOrder(r->left);
        printf("%d", r->info);
        inOrder(r->right);
    }
}

void preOrder (Node *r){
    if(r!=NULL){
        printf("%d", r->info);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder (Node *r){
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d", r->info);
    }
}



























