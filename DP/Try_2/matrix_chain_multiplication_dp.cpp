/* A naive recursive implementation that simply
  follows the above optimal substructure property */
#include<stdio.h>
#include<limits.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
    int table[n][n];
    for(int i = 0 ;i<n;i++)
        table[i][i] = 0;
    for(int l = 2;l < n; l++)
    {
        for(int i = 1; i < n-l+1;i++)
        {
            int val;
            int j = i + l - 1;
            table[i][j] = INT_MAX;
            for(int k = i ; k <= j - 1 ; k++)
            {
                val = table[i][k] + table[k+1][j] + p[i-1]*p[k]*p[j];
                if(val < table[i][j])
                    table[i][j] = val;
            }
        }
    }
    return table[1][n-1];
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum number of multiplications is %d ",
                          MatrixChainOrder(arr, n));

    getchar();
    return 0;
}
