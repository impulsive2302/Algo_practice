
#include<stdio.h>
#include<iostream>
using namespace std;
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int count( int S[], int m, int n)
{
    if(n < 0)
        return 0;
    if(m <= 0 && n >= 0)
        return 0;
    if(n == 0)
        return 1;
    return (count(S,m-1,n) + count(S,m,n-S[m-1]));
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
