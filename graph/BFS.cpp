#include<iostream>
#include<list>
#include<stdlib.h>
#include<queue>
using namespace std;
class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int vertex);
    void addEdge(int src, int dest);
    void BFS(int src);
};
Graph::Graph(int vertex)
{
    this->V = vertex;
    adj = new list<int>[vertex];
}
void Graph::addEdge(int src,int dest)
{
    adj[src].push_back(dest);
}
void Graph::BFS(int src)
{
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> Q;
    list<int>::iterator it;
    Q.push_back(src);
    visited[src] = true;
    while(!Q.empty())
    {
        int p = Q.front();
        cout<<p<<"     ";
        Q.pop_front();
        for(it = adj[p].begin();it!=adj[p].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                Q.push_back(*it);
            }
        }
    }
}
int main(){
//Create a graph given in the above diagram

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;

}
