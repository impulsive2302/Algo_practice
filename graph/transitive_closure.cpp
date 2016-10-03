#include<iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    bool **tc;
    list<int> *adj;
    void DFSUtil(int src, int dst);
public:
    void trasitiveclosure();
    void addEdge(int v, int w) { adj[v].push_back(w); }
    Graph(int V);
};
Graph :: Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    tc = new bool* [V];
    for(int i = 0;i<V;i++)
    {
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}
// A recursive DFS traversal function that finds
// all reachable vertices for s.
void Graph::DFSUtil(int s, int v)
{
    // Mark reachability from s to t as true.
    tc[s][v] = true;

    // Find all the vertices reachable through v
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (tc[s][*i] == false)
            DFSUtil(s, *i);
}

// The function to find transitive closure. It uses
// recursive DFSUtil()
void Graph::trasitiveclosure()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (int i = 0; i < V; i++)
        DFSUtil(i, i); // Every vertex is reachable from self.

    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Transitive closure matrix is \n";
    g.trasitiveclosure();

    return 0;
}
