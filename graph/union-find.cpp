#include<iostream>
#include<stdlib.h>
using namespace std;
struct edge{
    int src;
    int dst;
};

struct Graph{
    int vertex; int edges;
    struct edge* Edge;
};
struct Graph* Create_Graph(int v, int e)
{
    struct Graph* g = (struct Graph*) malloc(sizeof(Graph));
    g->vertex = v;
    g->edges = e;
    g->Edge = (struct edge*) malloc(e * sizeof(struct edge));
    return g;
}
int findParent(int * parent,int i)
{
    if(parent[i] == -1)
        return i;
    findParent(parent,parent[i]);
}
void union_g(int *parent,int xset,int yset)
{
    int xparent = findParent(parent, xset);
    int yparent = findParent(parent, yset);
    parent[xparent] = yparent;
}
bool isCycle(Graph *g)
{
    int* parent = (int*)malloc(g->vertex * sizeof(int));
    for(int i = 0;i<g->vertex;i++)
        parent[i] = -1;
    for(int i = 0;i<g->edges;i++)
    {
        int xset = findParent(parent,g->Edge[i].src);
        int yset = findParent(parent, g->Edge[i].dst);
        if(xset == yset)
            return true;
        union_g(parent,xset,yset);
    }
    return false;
}
int main()
{
    Graph* G = Create_Graph(3,3);
    /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */
    G->Edge[0].src = 0;
    G->Edge[0].dst = 1;
    G->Edge[1].src = 1;
    G->Edge[1].dst = 2;
    G->Edge[2].src = 0;
    G->Edge[0].dst = 2;
    if (isCycle(G))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );

    return 0;
}
