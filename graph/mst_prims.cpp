#include<iostream>
using namespace std;
#define V 5
void printmst(int parent[], int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
int minkey(int key[],bool mstset[])
{
    int min = 9999999;
    int index = -1;
    for(int i = 0;i < V; i++)
    {
        if(!mstset[i] && min > key[i]){
            min = key[i];
            index = i;
        }
    }
    return index;
}
void primMST(int graph[][V])
{
    int parent[V];
    int key[V];
    bool mstset[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstset[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for(int count =  0;count < V-1;count++)
    {
        int u = minkey(key, mstset);
        mstset[u] = true;
        for(int i = 0;i < V;i++)
        {
            if(graph[u][i] && !mstset[i] && key[i] > graph[u][i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    printmst(parent, graph);
}
int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);

    return 0;
}
