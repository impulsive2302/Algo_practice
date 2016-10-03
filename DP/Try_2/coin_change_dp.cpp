#include<stdio.h>
#include<iostream>
using namespace std;
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int count( int S[], int m, int n)
{
    //cout << "m = "<<m <<" n = "<<n<<endl;
    int table[m][n+1];
    for(int i = 0;i <= n;i++)
        table[i][0] = 1;
    for(int i = 0; i < m;i++)  // 0 to item -1
    {
        for(int j = 1;j<=n;j++)  // 1 to number
        {
            // Count of solutions including S[j]
            int x = (j- S[i] >=0)?  table[i][j- S[i]]: 0;

            // Count of solutions excluding S[j]
            int y = (i >= 1)? table[i-1][j]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[m-1][n];

}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int ans;
    ans = count(arr, m, 4);
    printf("%d ", ans);
    getchar();
    return 0;
}
