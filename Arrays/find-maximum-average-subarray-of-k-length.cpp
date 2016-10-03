#include<iostream>
using namespace std;
int findMaxAverage(int arr[],int n,int k)
{
    int sum = 0;
    for(int i =0;i<k;i++)
        sum+=arr[i];
    int  max_end = k-1;
    int max_sum = sum;
    for(int i=k;i<n;i++)
    {
        sum = sum +arr[i]-arr[i-k];
        if (sum > max_sum)
        {
            max_sum = sum;
            max_end = i;
        }
    }
    return max_end -k+1;
}
int main()
{
    int arr[] = {1, 12, -5, -6, 50, 3};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The maximum average subarray of "
         "length "<< k << " begins at index "
         << findMaxAverage(arr, n, k);
    return 0;
}
