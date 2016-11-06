#include <stdio.h>
#include <stdlib.h>

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
int visited[MAX_VERT];
int C[MAX_VERT][MAX_VERT];

/* A structure to represent an adjacency list node */
typedef struct node *nodePtr;

typedef struct node {
    int vtx;
    nodePtr nxt;
} node_t;

typedef struct vertexList {
    nodePtr head;
} vertexList_t;

typedef struct graph {
    int numVtx;
    vertexList_t *vList;
} graph_t;

void
initCost() 
{
    int i = 0;
    int j = 0;
    for (i = 0; i < MAX_VERT; i++) {
        for (j = 0; j < MAX_VERT; j++) {
            if (i == j) {
                C[i][j] = 0;
            } else {
                C[i][j] = MAX_COST;
            }
        }
    }
}

void
setCost(int i, int j, int c)
{
    C[i][j] = c;
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
printCost() 
{
    int i, j;
    printf("\n------------------Cost Matrix---------------------\n%5c", ' ');
    for (j = 0; j < MAX_VERT; j++) 
        printf("  [%d]", j);
    printf("\n");

    for (i = 0; i < MAX_VERT; i++) {
        printf("[%d] ", i);
        for (j = 0; j < MAX_VERT; j++) {
            if (C[i][j] == MAX_COST) {
                printf("%5c", '*');
            } else {
                printf("%5d", C[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------------------------------------\n");
}

node_t * 
newAdjListNode(int vtx)
{
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->vtx = vtx;
    newNode->nxt = NULL;
    return newNode;
}

graph_t *
createGraph(int V) 
{
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    graph->numVtx = V;
    graph->vList = (vertexList_t *) malloc(V * sizeof(vertexList_t));
      
    int i;
    for (i = 0; i < V; ++i)
        graph->vList[i].head = NULL;

    return graph;
}

graph_t *
insertVertex(graph_t *G)
{
    int i;

    /* Copy Current vertexList into temp */
    vertexList_t *tAdjList = G->vList;

    /* Allocate new vertexList */
    G->vList  = (vertexList_t *)malloc((G->numVtx + 1) * sizeof(vertexList_t));

    /* Copy over previous vertices to new vertexList */
    if (tAdjList) {
        for (i = 0; i < G->numVtx; i++) {
            G->vList[i] = tAdjList[i];
        }
    }

    G->numVtx++;
    G->vList[G->numVtx].head = NULL;

    /* Free old vertexList */
    if (tAdjList)
        free(tAdjList);
}

void 
insertEdge(graph_t *G, int src, int vtx)
{
    if ((src >= G->numVtx) || (vtx >= G->numVtx))
        return;

    node_t *T = G->vList[src].head;
    node_t *N;
    while (T) {
         if (T->vtx == vtx)
            return;
         T = T->nxt;
    } 

    N = newAdjListNode(vtx);
    N->nxt = G->vList[src].head;
    G->vList[src].head = N;

   // insertEdge(G, vtx, src);
}

void
deletEdgeNode(node_t **L, int n)
{
    node_t *tL;
    node_t *tNode; 

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
}

void
deleteEdge(graph_t *G, int src, int vtx)
{
    node_t *L;    
    node_t *tNode;    
    
    if ((src >= G->numVtx) || (vtx >= G->numVtx))
        return;

    deletEdgeNode(&(G->vList[src].head), vtx);
    deletEdgeNode(&(G->vList[vtx].head), src);
}

void
deleteVertex(graph_t *G, int V) 
{
    if (V >= G->numVtx)
        return;

    while (G->vList[V].head) {
        deleteEdge(G, V, G->vList[V].head->vtx);
    }
}

/* A utility function to print the adjacenncy list representation of graph */
void 
printGraph(graph_t *G)
{
    int v;

    for (v = 0; v < G->numVtx; ++v) {
        node_t *p = G->vList[v].head;
        printf("vertex[%d]", v);
        while (p) {
            printf(" -> %d", p->vtx);
            p = p->nxt;
        }
        printf("\n");
    }
}
#if 0
void
DFSHelper(node_t *L, int *visited)
{
    while (L} {
        if (!visited[L->vtx] {    
            visited[L->vtx] = 1;
            printf(" %2d ", L->vtx);
        }
        DFSHelper(L->nxt, L->vtx; &visited);
    }  
}
#endif
#if 0
void
DFSrecursive (graph_t *G, int V, int *visited)
{
    node_t *T = G->vList[V].head;

    while (T) {
        V = T->vtx;
        if (!visited[V]) {
            visited[V] = 1;
            printf("->%2d", V);
            DFSrecursive(G, V, visited);
        } else {
            T = T->nxt;
        }
    }
}

void 
DFS (graph_t *G, int V) 
{
    int visited[10] = {0};
    visited[V] = 1;
    printf("->%2d", V);
    DFSrecursive(G, V, visited);
}
#endif

void
DFS(graph_t *G, int V) 
{
    node_t *w;
    visited[V] = 1;
    printf("->%2d", V);
    for (w = G->vList[V].head; w; w = w->nxt) {
        if (!visited[w->vtx]) {
            DFS(G, w->vtx);
        }
    }
}

#ifdef BFS_Q
void
BFS(graph_t *G, int v)
{
    node_t *w;
    int front = rear = NULL;
    printf("->%2d", v);
    visited[v] = 1;
    addq(v);

    while(front) {
        v = deleteQ()
        for (w = G->vList[v].head; w; w = w->nxt) {
            if (!visited[w->vtx]) {
                printf("->%2d", w->vtx);
                addq(w->vtx);
                visited[w->vtx] = 1;
            }
        }
    }
}
#endif

#define TRUE  1
#define FALSE 0
int distance[8];
int found[8];
void
printDistance() 
{
    int i;
    for (i = 0; i < MAX_VERT; i++)
        if (distance[i] == MAX_COST) {
            printf("%5c", '*');
        } else {
            printf("%5d", distance[i]);
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
shortestPath(int v, int cost[MAX_VERT][MAX_VERT], int *distance, int *found)
{
    int i, u, w;
    int n  = MAX_VERT; 

    for (i =0; i < n; i++) {
        found[i] = FALSE;
        distance[i] = cost[v][i];
    }

    found[v] = TRUE;
    distance[v] = 0;

    printf("[%c]   ", '*');
    printDistance();

    for (i = 0; i < n - 2; i++) {
        u = choose(distance, n, found);
        for (w = 0; w < n; w++) {
            if (!found[w]) {
                if ((distance[u] + cost[u][w]) < distance[w]) { /* If cost of reaching w from u is less than known cost of reaching w , update new cost to reach w */
                    distance[w] = distance[u] + cost[u][w];  
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
    graph_t *G = createGraph(V);

    insertEdge(G, 1, 0);
    insertEdge(G, 2, 0);
    insertEdge(G, 2, 1);
    insertEdge(G, 3, 2);
    insertEdge(G, 4, 3);
    insertEdge(G, 4, 5);
    insertEdge(G, 5, 3);
    insertEdge(G, 5, 6);
    insertEdge(G, 5, 7);
    insertEdge(G, 6, 7);
    insertEdge(G, 7, 0);

    /* print the adjacency list representation of the above graph */
    printGraph(G);
    //insertVertex(G);

   // printGraph(G);
//    printf("deleting Edge 1 and 2 \n");
//    deleteEdge(G, 1, 2);
//    printGraph(G);
//    printf("deleting Vertix 2\n");
//    deleteVertex(G, 2);
//    printGraph(G);
    printf ("\nDFS[0]");
    DFS(G, 4);

    initCost();
    setCost(1, 0, 300);
    setCost(2, 0, 1000);
    setCost(2, 1, 800);
    setCost(3, 2, 1200);
    setCost(4, 3, 1500);
    setCost(4, 5, 250);
    setCost(5, 3, 1000);
    setCost(5, 6, 900);
    setCost(5, 7, 1400);
    setCost(6, 7, 1000);
    setCost(7, 0, 1700);
    printCost();
//shortestPath(int v, int **cost, int *distance, int n, int *found)
    V = 4;
    printHeader(V);
    shortestPath(V, C, distance, found);
    return 0;
}
