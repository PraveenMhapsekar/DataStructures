#include <stdio.h>
#include <stdlib.h>
#include "03-Queue.h"

/*
1. Graph
    graph_t* createGraph(int);
    graph_t* insertVertex(graph_t *, int vertex)
    graph_t* insertEdge(graph_t *, int src, int vtx, int weight)
    graph_t* deleteVertex(graph_t *, int vertext)
    graph_t* deleteEdge(graph_t *, int src, int vtx) 
    boolean  isEmpty(graph_t *)
    graph_t* listAdjacent(graph_t *, int) vertext
2. Elementary Graph Operation
    Depth First Search (DFS)
    Breadth First Search (BFS)
    Connected Components
    Spanning Trees
    Biconnected Componets
3. Minimum Cost Spanning Trees   
    kruskal's Algorithm
    Prim's Algorithm
    Sollin's Algorithm
4. Shortest Path and Transitive Closure
    Single Source/All Destination: Non Negative Edge Cost
    Single Source/All Destination: General Weights
    All Paired Shortest Paths
    Transitive Closure
5. Activity Networks   
    Activity-on-Vertex (AOV) Networks
    Activity-on-Edge (AOE) Networks
*/

#define MAX_VERT 8
#define MAX_COST 9999
#define TRUE  1
#define FALSE 0

int discovered[MAX_VERT];
int visited[MAX_VERT];
int distance[MAX_VERT];
int found[MAX_VERT];
int parent[MAX_VERT];

/* A structure to represent an adjacency list node */
typedef struct edgeNode *edgePtr;

typedef struct edgeNode {
    int vtx;
    int weight;
    edgePtr nxt;
} edgeNode_t;

typedef struct graph {
    int degree[MAX_VERT];
    int nvertices;
    int nedges;
    int directed;
    edgePtr edges[MAX_VERT];
} graph_t;

void
printParent() 
{
    int i;
    for (i = 0; i < MAX_VERT; i++) {
            printf("parent of %d -> %2d\n", i, parent[i]);
    }
    printf("\n");
}

int
getCost(graph_t *G, int src, int dst)
{
    edgePtr t = G->edges[src];

    while (t) {
        if (t->vtx == dst) {
           return (t->weight);
        }
        t = t->nxt;
    }
    return MAX_COST;
}

void
setCost(graph_t *G, int src, int dst, int cost)
{
    edgePtr t = G->edges[src];

    while (t) {
        if (t->vtx == dst) {
           t->weight = cost;
           return;
        }
        t = t->nxt;
    }
    fprintf(stderr, "No edge <%d, %d> found\n", src, dst);
}

void
printHeader(int v) 
{
    int j = 0;
    printf ("\nShortest Paths from Vertex %d\n%6c", v, ' ');
    for (j = 0; j < MAX_VERT; j++) 
        printf("  [%d]", j);
    printf("\n");
}

void
printCost(graph_t *G) 
{
    int i, j;
    printf("\n------------------Cost Matrix---------------------\n%5c", ' ');
    for (j = 0; j < MAX_VERT; j++) 
        printf("  [%d]", j);
    printf("\n");

    for (i = 0; i < MAX_VERT; i++) {
        printf("[%d] ", i);
        for (j = 0; j < MAX_VERT; j++) {
            if (getCost(G, i, j) == MAX_COST) {
                printf("%5c", '*');
            } else {
                printf("%5d", getCost(G, i, j));
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------\n");
}

graph_t *
createGraph(int V, int directed) 
{
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    graph->nvertices = V;
    graph->directed  = directed;
    //graph->edges = (edgeNode_t *) malloc(V * sizeof(edgeNode_t));
      
    int i;
    for (i = 0; i < MAX_VERT; ++i)
       graph->degree[i]= 0;

    return graph;
}

void 
insertEdge(graph_t *G, int src, int dst, int directed)
{
    if ((src >= G->nvertices) || (dst >= G->nvertices))
        return;

    edgeNode_t *T = malloc(sizeof(edgeNode_t));
    T->weight = 0;
    T->vtx = dst;
    T->nxt = G->edges[src];

    G->edges[src] = T;
    G->degree[src]++;

    if (directed) {
        insertEdge(G, dst, src, TRUE);
    } else {
        G->nedges++;
    }
}

void
deletEdgeNode(edgeNode_t **L, int n)
{
#if 0
    edgeNode_t *tL;
    edgeNode_t *tNode; 

    while (*L && (*L)->vtx == n) {
        tNode = *L;
        *L = (*L)->nxt;
        free(tNode);
        tNode = NULL;
    }

    tL = *L;

    while (tL && tL->nxt) {
        if (tL->nxt->vtx == n) {
            tNode = tL->nxt;
            tL->nxt = tL->nxt->nxt;
            free(tNode);
        } else {
            tL = tL->nxt;
        }
    } 
#endif    
}

void
deleteEdge(graph_t *G, int src, int vtx)
{
#if 0
    edgeNode_t *L;    
    edgeNode_t *tNode;    
    
    if ((src >= G->nvertices) || (vtx >= G->nvertices))
        return;

    deletEdgeNode(&(G->edges[src].head), vtx);
    deletEdgeNode(&(G->edges[vtx].head), src);
#endif    
}

void
deleteVertex(graph_t *G, int V) 
{
#if 0    
    if (V >= G->nvertices)
        return;

    while (G->edges[V].head) {
        deleteEdge(G, V, G->edges[V].head->vtx);
    }
#endif   
}

/* A utility function to print the adjacenncy list representation of graph */
void 
printGraph(graph_t *G)
{
    int v;

    for (v = 0; v < G->nvertices; ++v) {
        edgeNode_t *p = G->edges[v];
        printf("vertex[%d]", v);
        while (p) {
            printf(" -> %d", p->vtx);
            p = p->nxt;
        }
        printf("\n");
    }
}

void
clearSearch()
{
    int i;

    for (i = 0; i < MAX_VERT; i++) {
        visited[i]    = FALSE;
        discovered[i] = FALSE;
        parent[i]     = -1;
    }
}

void
DFS(graph_t *G, int V) 
{
    edgeNode_t *w;
    printf ("\nBFS[4]");
    visited[V] = 1;
    printf("->%2d", V);
    for (w = G->edges[V]; w; w = w->nxt) {
        if (!visited[w->vtx]) {
            DFS(G, w->vtx);
        }
    }
}

void
BFS(graph_t *G, int v)
{
    edgeNode_t *w;
    clearSearch();
    printf ("\nBFS[4]");
    queue_t *Q = createQ(MAX_VERT);
    enQueue(Q, v);
    discovered[v] = TRUE;

    while (isEmpty(Q) == 0) {
        v = deQueue(Q);
        printf("->%2d", v);
        visited[v] = TRUE;

        for (w = G->edges[v]; w; w = w->nxt) {
      //      if (visited[w->vtx] == FALSE) {
      //          printf("->%2d", w->vtx);
      //      }
            if (discovered[w->vtx] == FALSE) {
                enQueue(Q, w->vtx);
                discovered[w->vtx] = TRUE;
                parent[w->vtx] = v;
            }
        }
    }
    printf("\n");
}

void
find_path(int start, int end)
{
    if ((start == end) || (end == -1)) {
        printf("->%2d", start);
    } else {
        find_path(start, parent[end]);
        printf("->%2d", end);
    }
}

void
path(graph_t *G, int s, int e)
{
    clearSearch();
    BFS(G, s);
    printf("path between %d and %d is : ", s, e);
    find_path(s, e);
    printf("\n");
}


void
printDistance() 
{
    int i;
    for (i = 0; i < MAX_VERT; i++) {
        if (distance[i] == MAX_COST) {
            printf("%5c", '*');
        } else {
            printf("%5d", distance[i]);
        }
    }
    printf("\n");
}

int
choose (int *distance, int n, int *found)
{
    int i, min, minpos;
    min = 9999;
    minpos = -1;

    for (i = 0; i < MAX_VERT; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }

    found[minpos] = TRUE;
    printf("[%d]   ", minpos);  /* Print u */
    return minpos;
}

/* Dikjastra's */
void
shortestPath(graph_t *G, int v, int *distance, int *found)
{
    int i, u, w;
    int n  = MAX_VERT; 

    for (i =0; i < n; i++) {
        found[i] = FALSE;
        distance[i] = getCost(G, v, i);
    }

    found[v] = TRUE;
    distance[v] = 0;

    printf("[%c]   ", '*');
    printDistance();

    for (i = 0; i < n - 2; i++) {
        u = choose(distance, n, found);
        for (w = 0; w < n; w++) {
            if (!found[w]) {
                if ((distance[u] + getCost(G, u, w)) < distance[w]) { /* If cost of reaching w from u is less than known cost of reaching w , update new cost to reach w */
                    distance[w] = distance[u] + getCost(G, u, w);  
                }
            }
        } /* End of w-loop */
        printDistance();
    } /* End of i-loop */
}

int
main (void)
{
    int V = 8;
    graph_t *G = createGraph(V, FALSE);

    insertEdge(G, 1, 0, 0);
    insertEdge(G, 2, 0, 0);
    insertEdge(G, 2, 1, 0);
    insertEdge(G, 3, 2, 0);
    insertEdge(G, 4, 3, 0);
    insertEdge(G, 4, 5, 0);
    insertEdge(G, 5, 3, 0);
    insertEdge(G, 5, 6, 0);
    insertEdge(G, 5, 7, 0);
    insertEdge(G, 6, 7, 0);
    insertEdge(G, 7, 0, 0);

    /* print the adjacency list representation of the above graph */
    printGraph(G);

    DFS(G, 4);
    BFS(G, 4);
    printf("\n");
    printParent();

    setCost(G, 1, 0, 300);
    setCost(G, 2, 0, 1000);
    setCost(G, 2, 1, 800);
    setCost(G, 3, 2, 1200);
    setCost(G, 4, 3, 1500);
    setCost(G, 4, 5, 250);
    setCost(G, 5, 3, 1000);
    setCost(G, 5, 6, 900);
    setCost(G, 5, 7, 1400);
    setCost(G, 6, 7, 1000);
    setCost(G, 7, 0, 1700);
    printCost(G);

    /* Shortest path */
    V = 4;
    printHeader(V);
    shortestPath(G, V, distance, found);

    path(G, 4, 0);
    return 0;
}
