#include<iostream>
using namespace std;
int _lis(int arr[],int n, int *max)
{
    if (n==1)
        return 1;
    int result,max_till_here = 1;
    for(int i = 1;i<n;i++)
    {
        result = _lis(arr,i,max);
        if (arr[i-1] < arr[n-1] && result + 1 > max_till_here)
            max_till_here = result + 1;
    }
    if (*max < max_till_here)
       *max = max_till_here;

    // Return length of LIS ending with arr[n-1]
    return max_till_here;
}
int lis(int arr[], int n)
{
    int max = 1;
    _lis(arr,n,&max);
    return max;
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n",  lis( arr, n ));
    return 0;
}
