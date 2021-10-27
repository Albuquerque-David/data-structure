#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define  T_SIZE 20
#define MAX_NODES_SIZE 1000
#define MAX_EDGES_SIZE 499500

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
int KruskalMST(Graph* graph, int calc_states);
int Calc_Cities(Graph* graph);
int Calc_States(Graph* graph);

Graph* graph;

Graph* graph_cities;
Graph* graph_states;

int graph_cities_count;
int graph_states_count;
int graph_only_states_count;
int r, data_set;

int main()
{

    int t, x_coord[T_SIZE], y_coord[T_SIZE];
    int n;
    int i, j, k;
    int V; 
    int E;
    int distance;
    int minimum_cost_cities[T_SIZE];
    int minimum_cost_states[T_SIZE];
    int data_sets_count[MAX_NODES_SIZE];

    V = MAX_NODES_SIZE;
    E = MAX_EDGES_SIZE;

    t = 0;

    scanf("%d", &t);

    for(i = 0; i < t; i++) {
          
        graph = createGraph(V, E);

        graph_cities = createGraph(V,E);
        graph_states = createGraph(V,E);

        graph_cities_count = 0;
        graph_states_count = 0;
        graph_only_states_count = 0;

        data_set = 1;

        scanf("%d %d", &n, &r);

        for(j = 0; j < n; j++) {
            scanf("%d %d", &x_coord[j], &y_coord[j]);
        }

        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                if(j == k)
                    continue;
                distance = calcDistance(x_coord[j], x_coord[k], y_coord[j], y_coord[k]);

                if(distance <= r) {
                    graph_cities->edge[graph_cities_count].src = j;
                    graph_cities->edge[graph_cities_count].dest = k;
                    graph_cities->edge[graph_cities_count].weight = distance;            
                    graph_cities_count++;
                } else {
                    graph_states->edge[graph_states_count].src = j;
                    graph_states->edge[graph_states_count].dest = k;
                    graph_states->edge[graph_states_count].weight = distance;            
                    graph_states_count++;
                }
            }
        }

        graph_only_states_count = graph_states_count;

        minimum_cost_cities[i] = Calc_Cities(graph_cities);
        minimum_cost_states[i] = Calc_States(graph_states);
        data_sets_count[i] = data_set;

    }

    for(i = 0; i < t; i++) {
        printf("Case #%d: %d %d %d\n",i+1, data_sets_count[i], minimum_cost_cities[i], minimum_cost_states[i]);
    }

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
 
int comparator(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}

int KruskalMST(Graph* graph, int calc_states){
    int V = graph->V;
    Edge result[V];
    int e = 0; 
    int i = 0; 
    int minimumCost = 0;
    int v;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),comparator);
 
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
    
    for (i = 0; i < e; ++i)
    {
        if( calc_states == 0 ){
            graph_states->edge[graph_states_count].src = result[i].src;
            graph_states->edge[graph_states_count].dest = result[i].dest;
            graph_states->edge[graph_states_count].weight = result[i].weight;         
            graph_states_count++;
        }
        
        minimumCost += result[i].weight;
    }

    if( calc_states == 1 ) {
        for (i = 0; i < graph_states_count; i++) {
            if( result[i].weight < r ) {
                minimumCost -= result[i].weight;
            } else {
                data_set++;
            }            
        }
    }
    return minimumCost;
}

int Calc_Cities(Graph* graph)
{
    return KruskalMST(graph, 0);
}

int Calc_States(Graph* graph)
{
    return KruskalMST(graph, 1);
}

int calcDistance(int x1, int x2, int y1, int y2) {
    int distance;
    distance = round(sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ));
    return distance;
}