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

    char *line = NULL;
    size_t size_line;
    int vertex, edges;
    int i,j;
    int pos;
    int num_read;
    int num_chars;
    int *indegree;
    int *order;
    int order_pos;
    Adjacency *adj;
    Adjacency *aux;

    order_pos = 0;
    size_line = 0;

    scanf("%d %d\n", &vertex, &edges);

    adj = (Adjacency *)malloc(sizeof(Adjacency) * vertex);
    indegree = (int *)malloc(sizeof(int) * vertex);
    order = (int *)malloc(sizeof(int) * vertex);

    for(i = 0; i < vertex; i++){

        aux = &adj[i];

        getline(&line,&size_line,stdin);
        pos = 0;
        num_read = 0;
        
        while (sscanf(&line[pos], " %d %n", &num_read, &num_chars) > 0) {
            if(pos != 0){
                aux->right = (Adjacency *)malloc(sizeof(Adjacency));
                aux = aux->right;
            }

            pos += num_chars; 

            aux->data = num_read;
            aux->right = NULL;


        }
    }

    for(i = 0; i < vertex; i++){

        aux = &adj[i];
        while(aux != NULL){
            indegree[(aux->data)-1]++;
            aux = aux->right;
        }
    }

    for(i = 0; i < vertex; i++){

        if(indegree[i] == 0){
            order[order_pos] = i+1;
            order_pos++;
        }

    }

    for(i = 0; i < vertex; i++){

        j = order[i] - 1;
        aux = &adj[j];

        while(aux != NULL){
            indegree[(aux->data)-1]--;
            if(indegree[(aux->data)-1] == 0){
                order[order_pos] = (aux->data);
                order_pos++;
            }
            aux = aux->right;
        }
    }

    for(i = 0; i < vertex; i++){
        printf("%d ", order[i]);
    }

    return 0;

}
