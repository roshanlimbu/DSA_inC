#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>


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
                    printf("%d inserted at left of the %d\n",ptrnew->info, parent->info);
                } else {
                    parent->right=ptrnew;
                    printf("%d inserted at right of the %d\n",ptrnew->info, parent->info);
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
void bstRemove(Node *r, int d){

}
bool isLeft(Node *p){
    return (p->father)->left==p;
}
Node *getMinNode(Node *r){
    while(r->left!=NULL){
        r=r->left;
    } 
    return r;
}
Node *freeMemory(Node *r){
    if(r!=NULL){
        freeMemory(r->left);
        freeMemory(r->right);
        free(r);
    }
    return 0;
}
void inOrder(Node *r){
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ", r->info);
        inOrder(r->right);
    }
}
void preOrder(Node *r){
    if(r!=NULL){
        printf("%d ", r->info);
        inOrder(r->left);
        inOrder(r->right);
    }
}
void postOrder(Node *r){
    if(r!=NULL){
        inOrder(r->left);
        inOrder(r->right);
        printf("%d ", r->info);
    }
}
void bstSearch(Node *r, int target){
    if(r==NULL){
        printf("%d not found in the tree. \n", target);
    } else if(r->info==target){
        printf("%d found in the tree.\n ",target );
    } else if(r->info>target){
        bstSearch(r->left, target);
    } else {
        bstSearch(r->right, target);
    }
}
void search(Node *r){
    int target;
    printf("Enter a number to search: \n");
    scanf("%d", &target);
    bstSearch(r, target);
}
int main(){
    int choice, data;
    do {
        printf("Select your choice: \n1. Insert \n2. Remove \n3. Inorder Traversal\n") ;
        printf("4. Preorder Traversal \n5. Postorder Traversal \n6. Search \n7. Exit\n ");
        scanf("%d", &choice); 
        switch (choice) {
            case 1:
                bstInsert();
                break;

            case 2:
                printf("Enter the data to be removed.");
                scanf("%d", &data);
                bstRemove(root, data);
                break;

            case 3: 
                inOrder(root);
                printf("\n");
                break;
            case 4: 
                preOrder(root);
                printf("\n");
                break;
            case 5: 
                postOrder(root);
                printf("\n");
                break;
            case 6: 
                search(root);
                printf("\n");
                break;

            case 7: 
                exit(0);
                break;

        }


    }while (choice!=7);

    return 0;
}
