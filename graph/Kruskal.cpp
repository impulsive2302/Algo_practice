#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct edge{
    int src;
    int dest;
    int weight;
};

struct Graph
{
    int mvertex;
    int medge;
    edge* medges;
};
struct Graph* Create_Graph(int v, int e)
{
    string str= "Deepak";
    int len = str.length();
    cout<<len;
    struct Graph* g = (struct Graph*) malloc(sizeof(Graph));
    g->medge = e;
    g->mvertex = v;
    g->medges = (struct edge*) malloc(e*sizeof(edge));
    return g;
}
int mycomp(const void* edge1,const void* edge2)
{
    struct edge* temp1 = (struct edge*) edge1;
    struct edge* temp2 = (struct edge*) edge2;
    return (temp1->weight > temp2->weight);
}
struct subsets
{
    int parent;
    int rank;
};
int findParent(struct subsets* subsets,int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = findParent(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union_by_rank(struct subsets* subsets,int x, int y)
{
    int xparent = findParent(subsets,x);
    int yparent = findParent(subsets,y);
    if(subsets[xparent].rank < subsets[yparent].rank)
    {
        subsets[xparent].parent = yparent;
    }else if(subsets[xparent].rank > subsets[yparent].rank)
    {
        subsets[yparent].parent = xparent;
    } else{
        subsets[xparent].parent = yparent;
        subsets[xparent].rank++;
    }
}
void KruskalMST(struct Graph* graph)
{
    struct edge result[graph->mvertex];
    qsort(graph->medges,graph->medge,sizeof(graph->medges[0]),mycomp);
    struct subsets* subsets = (struct subsets*) malloc( graph->mvertex * sizeof(struct subsets));
    int e = 0;int i = 0;
    for (int v = 0; v < graph->mvertex; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e < graph->mvertex-1)
    {
        struct edge next_edge = graph->medges[i++];
        int xsubset = findParent(subsets,next_edge.src);
        int ysubset = findParent(subsets,next_edge.dest);
        if(xsubset != ysubset)
        {
            result[e++] = next_edge;
            Union_by_rank(subsets,xsubset,ysubset);
        }
    }
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                   result[i].weight);
    return;
}
int main()
{
    struct Graph* graph = Create_Graph(4,5);
    // add edge 0-1
    graph->medges[0].src = 0;
    graph->medges[0].dest = 1;
    graph->medges[0].weight = 10;

    // add edge 0-2
    graph->medges[1].src = 0;
    graph->medges[1].dest = 2;
    graph->medges[1].weight = 6;

    // add edge 0-3
    graph->medges[2].src = 0;
    graph->medges[2].dest = 3;
    graph->medges[2].weight = 5;

    // add edge 1-3
    graph->medges[3].src = 1;
    graph->medges[3].dest = 3;
    graph->medges[3].weight = 15;

    // add edge 2-3
    graph->medges[4].src = 2;
    graph->medges[4].dest = 3;
    graph->medges[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
