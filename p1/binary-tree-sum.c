#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node {
    int chave;
    struct Node *esq;
    struct Node *dir;
    int soma;
} Node;
 
Node *add_node(int key);
Node *fill_all_sums(Node *root);
int calc_sum(Node *node);
Node *insert(int value, Node *node);
Node *insert_ordering(int value, Node *root);
void printTree(Node *node);
void freeTree(Node *node);


int main() {

    Node *root = NULL;



    root = insert_ordering(10, root);
    root = insert_ordering(5, root);
    root = insert_ordering(4, root);
    root = insert_ordering(6, root);
    root = insert_ordering(15, root);
    root = insert_ordering(17, root);
    root = insert_ordering(18, root);
    root = insert_ordering(16, root);
    root = insert_ordering(14, root);
    root = insert_ordering(19, root);

    /*root = fill_all_sums(root);*/

    printTree(root);
    printf("\n");
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

Node* add_node(int value) {

    Node *node = (Node *)malloc(sizeof(Node));
    node->chave = value;
    node->esq = NULL;
    node->dir = NULL;
    node->soma = 0;
    return node;

}

Node* insert(int value, Node *node) {

    if( node == NULL ) {
        return add_node(value);
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

Node* insert_ordering(int value, Node *root) {

    /**
    * Se árvore vazia.
    **/
    if( root == NULL ) {
        return add_node(value);
    }

    /**
    * Se valor repetido.
    **/
    if( value == root->chave ) {
        return root;
    }

    /**
    * Inserir esquerda e calcular soma
    **/
    if( value < root->chave ) {
        root->esq = insert_ordering(value,root->esq);
        root->soma = calc_sum(root->esq) + calc_sum(root->dir) + root->chave;
    }

    /**
    * Inserir direita e calcular soma
    **/
    if( value > root->chave ) {
        root->dir = insert_ordering(value,root->dir);
        root->soma = calc_sum(root->esq) + calc_sum(root->dir) + root->chave;
    }

    return root;
}

Node* fill_all_sums(Node* root) {

    if(root == NULL) {
        return NULL;
    }

    root->soma = calc_sum(root->esq) + calc_sum(root->dir) + root->chave;
    return root;
}

int calc_sum(Node* node) {

    int sum = 0;
    if(node != NULL) {

        if(node->soma != 0) {
            return node->soma;
        }

        sum += calc_sum(node->esq);
        sum += calc_sum(node->dir);
        node->soma = node->chave + sum;
        return node->soma;

    }
    else {
        return 0;
    }

}

