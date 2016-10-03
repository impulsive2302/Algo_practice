#include<stdio.h>

int count( int S[], int m, int n )
{
    int arr[m][n+1];

    for(int i = 0;i<m;i++)
        arr[i][0] = 1;

    for(int i = 0;i < m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            //including this element
            int x = (j>=S[i])? arr[i][j-S[i]]: 0;

            //excluding this element
            int y = (i>=1) ?  arr[i-1][j]:0;

            arr[i][j] =  x + y;
        }
    }
    return arr[m-1][n];
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", count(arr, m, n));
    return 0;
}
