#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  T_SIZE 20

typedef struct Edge {
    int src, dest, weight;
} Edge;
 
typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V, int E);
void Union(Subset subsets[], int x, int y);
int Find(Subset subsets[], int i);
int myComp(void* a, void* b);
int calcDistance(int x1, int x2, int y1, int y2);
void KruskalMST(Graph* graph);

int main()
{

    /*int t, t_array[T_SIZE];
    int n, r;
    int x, y;
    int i;
    int a, b, c*/
    int V; 
    int E;
    Graph* graph;

    V = 4;
    E = 5;
    
    graph = createGraph(V, E);

    /*graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 2;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 1;*/

    /*
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 100;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 200;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 100;*/

    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 14;
 
    graph->edge[1].src = 2;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 10;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 100;

    /*
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 100;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 200;
 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 100;*/

 
    KruskalMST(graph);

    /*scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%d %d", &n, &r);
    }

    for(i = 0; i < t; i++) {
        printf("Case #%d: %d %d %d\n", a, b, c);
    }*/

    return 0;
}

Graph* createGraph(int V, int E)
{
    Graph* graph;
    graph = (Graph*)(malloc(sizeof(Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (Edge*)malloc(sizeof(Edge)*E);
 
    return graph;
}


 
int Find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
            = Find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(Subset subsets[], int x, int y)
{
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(void* a, void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0; 
    int i = 0; 
    int minimumCost = 0;
    int v;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
 
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
 
    for (v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];
 
        int x = Find(subsets, next_edge.src);
        int y = Find(subsets, next_edge.dest);
        
        
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        
    }

    printf(
        "Following are the edges in the constructed MST\n");
    
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src,
            result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning tree : %d\n\n",minimumCost);
    return;
}

int calcDistance(int x1, int x2, int y1, int y2) {
    return round(sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ));
}