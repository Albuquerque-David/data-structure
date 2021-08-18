/**
 * 
 * Topological-Sort
 * Author: github.com/Albuquerque-David
 * Under Apache License Version 2.0, January 2004
 * 
 */

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Adjacency{
    int data;
    struct Adjacency *right;
} Adjacency;

int main(int argc, char** argv)
{   

    char *linha = NULL;
    size_t tamLinha;
    int vertices, arestas;
    int i;
    int pos;
    int numLido;
    int numChars;
    Adjacency *adj;
    Adjacency *aux;

    tamLinha = 0;

    scanf("%d %d\n", &vertices, &arestas);

    adj = (Adjacency *)malloc(sizeof(Adjacency) * vertices);

    printf("Li vertices = %d e arestas = %d\n",vertices,arestas);
    for(i = 0; i < vertices; i++){

        aux = &adj[i];

        getline(&linha,&tamLinha,stdin);
        pos = 0;
        numLido = 0;
        
        while (sscanf(&linha[pos], " %d %n", &numLido, &numChars) > 0) {
            if(pos != 0){
                aux->right = (Adjacency *)malloc(sizeof(Adjacency));
                aux = aux->right;
            }

            pos += numChars; 

            aux->data = numLido;
            aux->right = NULL;

            if(strlen(linha) != 0){
                printf(" insere em adj [ %d ] o vertice %d\n",i+1, numLido);      
            }
        }
    }


    for(i = 0; i < vertices; i++){

        aux = &adj[i];
        printf("Vertice %d", i+1);
        while(aux != NULL){
            printf("->%d",aux->data);
            aux = aux->right;
        }

        printf("\n");

    }

    return 0;

}
