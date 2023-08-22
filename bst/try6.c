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
    printf("Enter the data to insert: \n");
    scanf("%d", &info);
    ptrnew=createNode(info);

    while(1){
        if(curr==NULL){
            if(root==NULL){
                root = ptrnew;
                printf("%d inserted at the root.\n ", ptrnew->info);
            } else {
                if(ptrnew->info<parent->info){
                    parent->left=ptrnew;
                    printf("%d inserted at the left of %d. " ,ptrnew->info, parent->info);
                } else {
                    parent->right=ptrnew;
                    printf("%d inserted at the right of %d. " ,ptrnew->info, parent->info);
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

bool isLeft(Node *p){
    return (p->father)->left==p;
}

Node * getMinNode(Node *r){
    while(r->left!=NULL){
        r=r->left;
    }
    return r;
}
void bstRemove(Node *r, int d){
    if(r==NULL){
        printf("Node not found.\n");
        return;
    }
    if(d<r->info){
        bstRemove(r->left, d);
    } else if(d>r->info){
        bstRemove(r->right,  d);
    } else {
        if(r->left==NULL && r->right==NULL){
            if(r==root){
                root = NULL;
            } else if(isLeft(r)){
                (r->father)->left=NULL;
            } else {
                (r->father)->right=NULL;
            }
            free(r);
        }
    }
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
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(Node *r){
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->info);
    }
}
void bstSearch(Node *r, int target){
    if(r==NULL){
        printf("%d doesn't exist in the tree. \n", target);
    } else if(r->info==target){
        printf("%d exists in the tree. \n" , target);
    } else if(target<r->info){
        bstSearch(r->left, target);
    } else {
        bstSearch(r->right, target);
    }
}

void search(Node *r){
    int target;
    printf("Enter the number you want to search:\n ");
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










