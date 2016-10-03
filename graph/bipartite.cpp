// C++ program to find out whether a given graph is Bipartite or not
#include <iostream>
#include <queue>
#define V 4
using namespace std;
bool isBipartite(int G[][V], int src)
{
    int colorarr[V] = {-1};
    colorarr[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i<V;i++)
        {
            if(G[u][i] && (colorarr[i] == -1))
            {
                colorarr[i] = 1 - colorarr[u];
                q.push(i);
            }
            else if(G[u][i] && (colorarr[i] == colorarr[u]))
                return false;
        }
    }
    return true;
}
// Driver program to test above function
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
