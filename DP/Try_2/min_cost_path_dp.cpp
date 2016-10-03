/* A Naive recursive implementation of MCP(Minimum Cost Path) problem */
#include<stdio.h>
#include<limits.h>
#define R 3
#define C 3

int min(int x, int y, int z);

/* Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]*/
int minCost(int cost[R][C], int m, int n)
{
    int dp[R][C];
    dp[0][0] = cost[0][0];
    for(int i = 1;i < R;i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for(int i = 1;i < C;i++)
        dp[0][i] = dp[0][i-1] + cost[0][i];

    for(int i = 1;i<R;i++)
    {
       for(int j = 1;j<C;j++)
       {
           dp[i][j] = cost[i][j] + min(dp[i-1][j-1],
                                       dp[i-1][j],
                                       dp[i][j-1]);
       }
    }
    return dp[m][n];
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

/* Driver program to test above functions */
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}

