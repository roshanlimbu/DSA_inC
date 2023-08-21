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
        exit(1);
    }
    ptrnew->info = info;
    ptrnew->father = ptrnew->left = ptrnew->right = NULL;
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

bool isLeft(Node* p) {
    return  (p->father)->left == p;
}

Node* getMinNode(Node* r) {
    while (r->left != NULL)
        r = r->left;
    return r;
}
Node* freeMemory(Node* r) {
    if (r != NULL) {
        freeMemory(r->left);
        freeMemory(r->right);
        free(r);
    }
    return 0;
}

void bstRemove(Node* r, int d) {
    Node* temp;
    if (r == NULL)
        printf("%d does not exist in the tree.\n", d);
    else if (r->info == d) {
        if (r->left == NULL && r->right == NULL) {
            if (r->father == NULL)
                root = NULL;
            else if (isLeft(r))
                (r->father)->left = NULL;
            else
                (r->father)->right = NULL;
            free(r);
        }
        else if (r->left == NULL) {
            if (r->father == NULL)
                root = r->right;
            else if (isLeft(r))
                (r->father)->left = r->right;
            else
                (r->father)->right = r->right;
            free(r);
        }
        else if (r->right == NULL) {
            if (r->father == NULL)
                root = r->left;
            else if (isLeft(r))
                (r->father)->left = r->left;
            else
                (r->father)->right = r->left;
            free(r);
        }
        else {
            temp = getMinNode(r->right);
            r->info = temp->info;
            temp->info = d;
            bstRemove(temp, d);
            return;
        }
        printf("%d removed from the tree.\n", d);
    }
    else if (r->info > d)
        bstRemove(r->left, d);
    else
        bstRemove(r->right, d);
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

void bstSearch(Node* r, int target) {
    if (r == NULL)
        printf("%d does not exist in the tree.\n", target);
    else if (r->info == target)
        printf("%d found in the tree.\n", target);
    else if (r->info > target)
        bstSearch(r->left, target);
    else
        bstSearch(r->right, target);
}

void search(Node* r) {
    int target;
    printf("Enter a number to be searched: ");
    scanf("%d", &target);
    bstSearch(r, target);
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
                bstInsert();
                break;
            case '2':
                printf("Enter a number to be removed: ");
                scanf("%d", &data);
                bstRemove(root, data);
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
                search(root);
                break;
            case '7':
            freeMemory(root);
            exit(0);
        }
        while(getchar()!='\n');
    }
    return 0;
}

