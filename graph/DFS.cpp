#include<iostream>
#include<list>
using namespace std;

class Graph{
    int vertex;
    list<int>* adj;

public:
    Graph(int v)
    {
        this->vertex = v;
        adj = new list<int>[v];
    }
    void addEdge(int src, int dest){
        adj[src].push_back(dest);
    }
    void DFS_Util(int src, bool visited[])
    {
        cout<<src<<"    ";
        visited[src] = true;
        list<int>::iterator it;
        for(it = adj[src].begin();it!=adj[src].end();it++)
        {
            if(!visited[*it])
                DFS_Util(*it,visited);
        }
    }
    void DFS(int src)
    {
        bool * visited = new bool[vertex];
        for(int i = 0;i<vertex;i++)
            visited[i] = false;
        DFS_Util(src,visited);
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}
