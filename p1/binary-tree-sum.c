#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node {
    int chave;
    struct Node *esq;
    struct Node *dir;
    int soma;
} Node;
 
Node *addNode(int key);
int sum(Node *N);
Node *insert(int value, Node *node);
void printTree(Node *node);
void freeTree(Node *node);


int main() {

    struct Node *root = NULL;

    root = insert(5, root);
    root = insert(4, root);
    root = insert(3, root);
    root = insert(6, root);
    root = insert(10, root);
    root = insert(14, root);

    printTree(root);
    freeTree(root);

    return 0;
}

void freeTree(Node *root) {
    if(root != NULL) {
        freeTree(root->esq);
        freeTree(root->dir);
        free(root);
    }
}

void printTree(Node *root) {
    if(root != NULL) {
        printTree(root->esq);
        printTree(root->dir);
        printf("%d(%d) ", root->chave,root->soma);
    }
}

Node* addNode(int value) {

    Node *node = (Node *)malloc(sizeof(Node));
    node->chave = value;
    node->esq = NULL;
    node->dir = NULL;
    node->soma = -1;
    return node;

}

Node* insert(int value, Node *node) {

    if( node == NULL ) {
        return addNode(value);
    }

    if( value == node->chave ) {
        return node;
    }

    if( value < node->chave ) {
        node->esq = insert(value,node->esq);
    }

    if( value > node->chave ) {
        node->dir = insert(value,node->dir);
    }

    return node;

}


