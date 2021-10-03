#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* insert_ordered_node(Node* list, int new_node_value);

int main(void) {

    Node *list, *aux;

    list = NULL;

    list = insert_ordered_node(list, 3);
    list = insert_ordered_node(list, 6);
    list = insert_ordered_node(list, 2);
    list = insert_ordered_node(list, 8);
    list = insert_ordered_node(list, 9);
    list = insert_ordered_node(list, 1);

    aux = list;

    while(aux != NULL){
		printf("%d ",aux->value);
		aux=aux->next;
	}

    printf("\n");

    return 0;
}

Node* insert_ordered_node(Node *list, int new_node_value) {

    Node *aux, *ant;

    if(list == NULL) {
        list = (Node *)malloc(sizeof(Node));
        list->value = new_node_value;
        list->next = NULL;
        return list;
    }

    aux = list;

    /**
    *
    * Beginning of list
    *
    **/
    if(new_node_value < list->value) {
        list = (Node *)malloc(sizeof(Node));
        list->value = new_node_value;
        list->next = aux;
        return list;
    }

    while(new_node_value > aux->value && aux->next != NULL) {
        ant = aux;
        aux = aux->next;
    }

    /**
    *
    * End of list
    *
    **/
    if(new_node_value > aux->value) {
        aux->next = (Node *)malloc(sizeof(Node));
        aux = aux->next;
        aux->value = new_node_value;
        aux->next = NULL;
        return list;
    }

    /**
    *
    * Middle of list
    *
    **/
    ant->next=(Node *)malloc(sizeof(Node));
    ant=ant->next;
    ant->value=new_node_value;
    ant->next=aux;
    aux=NULL;
    ant=aux;
    return list;

}

