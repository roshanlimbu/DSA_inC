#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int info;
    struct Node *left;
    struct  Node *right;
    struct  Node *father;
} Node;


Node *root = NULL;


Node *createNode(int info){
    Node *ptrnew =  (Node *)malloc(sizeof(Node));
    if(ptrnew==NULL){
        printf("Memory allocation failed.");
        exit(0);
    }

    ptrnew->info= info;
    ptrnew->right=ptrnew->left=ptrnew->father = NULL;
    return ptrnew;
}


void bstInsert(){
    int n;
    Node *curr=root, *ptrnew, *parent = NULL;
    printf("Enter the number to be inserted. ");
    scanf("%d" , &n);
    ptrnew = createNode(n);
    while(1){
        if(curr==NULL){
            if(root==NULL){
                root = ptrnew;            
                printf("%d inserted at the root.", ptrnew->info);
            } else {
                if(ptrnew->info<parent->info){
                    parent->left=ptrnew;
                    printf("%d inserted at the left of %d", ptrnew->info, parent->info);
                } else {
                    parent->right=ptrnew;
                    printf("%d inserted at the right of %d", ptrnew->info, parent->info);
                }
            }
        } else if(ptrnew->info<curr->info){
            parent=curr;
            curr = curr->left;
        } else {
            parent=curr;
            curr=curr->right;
        }

    }
}

