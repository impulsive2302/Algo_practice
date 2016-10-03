#include <bits/stdc++.h>
using namespace std;

// The function returns number of
// distinct absolute values among
// the elements of the array
int distinctCount(int arr[], int n)
{
    int count = n;
    int i = 0;
    int j = n-1;
    while(i < j)
    {
        while(i!=j && arr[i]==arr[i+1])
        {
            i++;
            count--;
        }
        while(i!=j && arr[j]==arr[j-1])
        {
            j--;
            count--;
        }
        if(i==j)
            break;
        int sum = arr[i] + arr[j];
        if(sum == 0) {
            i++;j--;
            count--;
        }
        if(sum > 0)
            j--;
        if(sum<0)
            i++;
    }
    return count;
}

// Driver code
int main()
{
    int arr[] = {-2, -1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Count of absolute distinct values : "
         << distinctCount(arr, n);

    return 0;
}
