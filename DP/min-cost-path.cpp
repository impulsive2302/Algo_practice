#include<iostream>
using namespace std;
int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
#define R 3
#define C 3
int minCost(int cost[R][C], int m, int n)
{
    int path_cost[R][C];

    path_cost[0][0] = cost[0][0];

    for(int i = 1;i<=m;i++)
        path_cost[i][0] = cost[i][0] +  path_cost[i-1][0];

    for(int i = 1;i<=n;i++)
        path_cost[0][i] = cost[0][i] +  path_cost[0][i-1];

        for(int i =1;i<=m;i++)
        {
            for(int j =1;j<=n;j++)
            {
                path_cost[i][j] = cost[i][j]+min(path_cost[i-1][j],
                                                 path_cost[i][j-1],
                                                 path_cost[i-1][j-1]
                                                 );
            }
        }
        return path_cost[m][n];
}
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}


