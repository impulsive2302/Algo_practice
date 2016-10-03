#include<iostream>
#include<cstdlib>
using namespace std;
struct adj_list_node{
    int dest;
    struct adj_list_node* next;
}adj_list_node;

struct adj_list
{
    struct adj_list_node* head;
};
struct Graph{
    int V;
    struct adj_list* array;
};
struct adj_list_node* new_adj_list_node(int dt)
{
    struct adj_list_node* temp = (struct adj_list_node*)malloc(sizeof(adj_list_node));
    temp->dest = dt;
    temp->next = NULL;
}
struct Graph* Create_graph(int v)
{
    Graph* temp = (struct Graph*) malloc(sizeof(Graph));
    temp->V = v;
    temp->array = (struct adj_list*) malloc(v*sizeof(struct adj_list));
    for(int i = 0;i<v;i++)
    {
        temp->array[i].head = NULL;
    }
    return temp;
}
void addEdge_directed(Graph* g, int src, int dest)
{
    struct adj_list_node* temp = g->array[src].head;
    struct adj_list_node* new_node = new_adj_list_node(dest);
    //cout<<"adding edge between"<<src<<"--->"<<dest<<endl;
    if(temp == NULL)
    {
        g->array[src].head = new_node;
        //cout<<"assigning new node to "<<src<<endl;
    } else {
        //cout<<"appending  new node to "<<src<<endl;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}
void addEdge_undirected(Graph* g, int src, int dest)
{
    struct adj_list_node* new_node = new_adj_list_node(dest);
    new_node->next =  g->array[src].head;
    g->array[src].head = new_node;

    //As the graph is directed as in hte destination also
    new_node = new_adj_list_node(src);
    new_node->next =  g->array[dest].head;
    g->array[dest].head = new_node;
}
void traverse_graph(Graph* g)
{
    int vertex = g->V;
    for(int i = 0;i<vertex;i++)
    {
        struct adj_list_node* temp = g->array[i].head;
        cout<<"SRC "<< i<<"-->";
        while(temp!=NULL)
        {
            cout<<temp->dest<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int V = 5;
    Graph* graph = Create_graph(V);
    addEdge_undirected(graph, 0, 1);
    addEdge_undirected(graph, 0, 4);
    addEdge_undirected(graph, 1, 2);
    addEdge_undirected(graph, 1, 3);
    addEdge_undirected(graph, 1, 4);
    addEdge_undirected(graph, 2, 3);
    addEdge_undirected(graph, 3, 4);
    traverse_graph(graph);
}
