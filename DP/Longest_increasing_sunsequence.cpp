#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int lis(int arr[],int size)
{
    int sub_arr[size] = {1};
    for(int i = 1;i<size;i++)
    {
        for(int j = 0; j<i ;j++)
        {
            if(arr[i]>arr[j])
                sub_arr[i] = max(sub_arr[i],1+sub_arr[j]);
        }
    }
    int max = INT_MIN;
    for(int i =0;i<size;i++)
    {
        if(sub_arr[i]>max)
            max = sub_arr[i];
    }
    return max;
}
int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", lis( arr, n ) );
  return 0;
}

