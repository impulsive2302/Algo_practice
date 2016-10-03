#include<iostream>
#include<map>
using namespace std;
int getPairsCount(int arr[],int size,int sum)
{
    map<int,int> m;
    for(int i =0;i<size;i++)
        m[arr[i]]++;
    int twice = 0;
    for(int i =0;i<size;i++)
    {
        twice += m[sum-arr[i]];

        if(sum-arr[i] == arr[i])
            twice--;
    }
    return twice/2;
}
// Driver function to test the above function
int main()
{
    int arr[] = {1, 5, 7, -1, 5} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
    return 0;
}
