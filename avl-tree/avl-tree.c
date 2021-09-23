#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;
 
Node *addNode(int key);
int height(Node *N);
Node *insert(int value, Node *node);
int getBalance(Node *node);
Node *rightRotate(Node *n);
Node *leftRotate(Node *n);
void printTree(Node *node);
void freeTree(Node *node);


int main() {
    int value;
    struct Node *root = NULL;
    char str[100];

    while(!feof(stdin)) {
        if(scanf("%s",str) == 1) {
            if(str[0] == 'p') {
                printTree(root);
                printf("\n");
            }

            if(str[0] == 'i') {

                if(scanf("%d",&value) == 1) {
                    root = insert(value,root);
                }
    
            }
        }
    }

    freeTree(root);

    return 0;
}

void freeTree(Node *root) {
    if(root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void printTree(Node *root) {
    if(root != NULL) {
        printf("%d(%d) ", root->value,root->height);
        printTree(root->left);
        printTree(root->right);
    }
}

Node* addNode(int value) {

    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;

}

Node* insert(int value, Node *node) {

    int balance;

    if( node == NULL ) {
        return addNode(value);
    }

    if( value == node->value ) {
        return node;
    }

    if( value < node->value ) {
        node->left = insert(value,node->left);
    }

    if( value > node->value ) {
        node->right = insert(value,node->right);
    }

    node->height = ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right)) + 1;

    balance = getBalance(node);

    if(balance > 1 && value < node->left->value) {
        return rightRotate(node);
    }

    if(balance < -1 && value > node->right->value) {
        return leftRotate(node);
    }

    if(balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *rightRotate(Node *n) {
    Node *x = n->left;
    Node *T2 = x->right;

    x->right = n;
    n->left = T2;

    n->height = ((height(n->left) > height(n->right)) ? height(n->left) : height(n->right)) + 1;
    x->height = ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *n) {
    Node *x = n->right;
    Node *T2 = x->left;

    x->left = n;
    n->right = T2;

    n->height = ((height(n->left) > height(n->right)) ? height(n->left) : height(n->right)) + 1;
    x->height = ((height(x->left) > height(x->right)) ? height(x->left) : height(x->right)) + 1;

    return x;
}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
