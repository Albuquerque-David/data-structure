#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;
 
Node *addNode(int key);
int max(int a, int b);
int height(Node *N);
Node *insert(int value, Node *node);
int getBalance(Node *node);
Node *rightRotate(Node *n);
Node *leftRotate(Node *n);
void printTree(Node *node);
 

int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int main() {
    int value;
    struct Node *root = NULL;
    while(1) {
        scanf("%d", &value);
        if(value == -1)
            break;
        root = insert(value,root);
    }
    
    printTree(root);

    return 0;
}

void printTree(Node *root) {
    if(root != NULL) {
        printf("%d ", root->value);
        printTree(root->left);
        printTree(root->right);
    }
}

Node* addNode(int value) {

    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;

}

Node* insert(int value, Node *node) {

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

    return node;
}

