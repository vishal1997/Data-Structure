#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int vertex, E;
    struct Edge *edge;
};

struct subset {
    int parent;
    int rank;
};


void kruskalMST(struct Graph *graph );
int findSet(struct subset set[], int i);
int compare(const void *a, const void *b);
struct Graph *createGraph(int vertex, int E) ;
void unionSet(struct subset set[], int x, int y) ;


struct Graph *createGraph(int vertex, int E) {
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    graph->vertex=vertex;
    graph->E=E;

    graph->edge=(struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
} ;


int findSet(struct subset set[], int i) {
    if(set[i].parent!=i)
        set[i].parent=findSet(set, set[i].parent);
    return set[i].parent;
}

int compare(const void *a, const void *b) {
    struct Edge *a1=(struct Edge *)a;
    struct Edge *b1=(struct Edge *)b;
    return a1->weight > b1->weight;
}

void unionSet(struct subset set[], int x, int y) {
    int xParent=findSet(set, x);
    int yParent=findSet(set, y);
    if(set[xParent].rank < set[yParent].rank)
        set[xParent].parent=yParent;
    else if(set[xParent].rank > set[yParent].rank)
        set[yParent].parent=xParent;
    else {
        set[yParent].parent=xParent;
        set[xParent].rank++;
    }
}

void kruskalMST(struct Graph *graph ) {
    int vertex=graph->vertex;
    struct Edge result[vertex];
    int i=0,e=0;
    struct subset *set=(struct subset *)malloc(vertex*sizeof(struct subset));
    for(i=0;i<vertex;i++) {
        set[i].parent=i;
        set[i].rank=0;
    }
    i=0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),compare);
    while(e<vertex-1) {
        struct Edge nextEdge=graph->edge[i++];
        int x=findSet(set,nextEdge.src);
        int y=findSet(set,nextEdge.dest);
        if(x!=y) {
            result[e++]=nextEdge;
            unionSet(set,x,y);
        }
    }
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return;
}
int main() {
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalMST(graph);

    return 0;
}
