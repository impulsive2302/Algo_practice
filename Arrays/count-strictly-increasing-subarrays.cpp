#include<bits/stdc++.h>
using namespace std;
int countIncreasing(int arr[],int n)
{
    int ans = 0;
    int len = 1;
    for(int i = 1;i<n;i++)
    {
        if(arr[i] > arr[i-1])
            len++;
        else
        {
            ans += len*(len-1)/2;
            len = 1;
        }
    }
    if(len > 1)
        ans += len*(len-1)/2;
    return ans;
}
int main()
{
  int arr[] = {1, 2, 2, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Count of strictly increasing subarrays is "
       << countIncreasing(arr, n);
  return 0;
}
