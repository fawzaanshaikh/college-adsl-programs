#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// Structure to define weighted edge
struct Edge{
    int src,dest,weight;

};

// Structure to represent a connnected graph
struct Graph{ 
    int V;
    int E;

    // Here graph is an array of edges because we want to sort them on the basis of edges. No other pattern.   
    struct Edge * edge;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph; // (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
};

// A structure to represent a subset for union and find
struct subset{
    int parent;
    int rank;
};


// Find set of an element
// path compression technique
int find(struct subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
void Union(struct subset subsets[],int x,int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    // Attach smaller rank tree under root of high rank tree
    // union by rank
    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    // If ranks are same, then make one as root and increment/
    // its rank by one
    else{
        //ToDo:: 
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++; 
    }
}

// To sort edges in ascending order
int myComp(const void*a, const void*b){  
    struct Edge*a1 = (struct Edge*) a;
    struct Edge*b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph){
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);

    struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));

    for(int v = 0; v < V;++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;

    }

    while(e< V-1){
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets,next_edge.src);
        int y = find(subsets, next_edge.dest);

        if(x != y){
            result[e++] = next_edge;
            Union(subsets,x,y);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    for(int i=0;i<e;++i){
            printf("%d -- %d == %d\n",result[i].src,result[i].dest,result[i].weight);
            
        }
    return;
}

// Driver code
int main(){
    int V = 4;
    int E = 5;
    struct Graph* graph = createGraph(V,E);

    // Add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // Add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // Add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // Add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // Add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}