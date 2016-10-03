#include<iostream>
using namespace std;
struct Edge
{
    int src;
    int dst;
    int weight;
};
struct graph
{
    int V,E;
    struct Edge* edge;;
};
struct graph* create_graph(int vertex,int edge)
{
    struct graph* = (struct graph*)  malloc( sizeof(struct Graph));
    graph->E = edge;
    graph->V = vertex;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof( struct Edge ));
};
struct
int main()
{

}
