#include<iostream>
using namespace std;
int getInvCount(int a[],int n)
{
    int inv = 0;
    for(int i = 0;i < n;i++)
    {
        int small =0;
        int great =0;
        for(int j =i+1;j<n;j++)
        {
            if(a[j]<a[i])
                great++;
        }
        for(int j =i-1;j>=0;j--)
        {
            if(a[j]>a[i])
                small++;
        }
        inv+=small*great;
    }
    return inv;
}
int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Inversion Count : " << getInvCount(arr, n);
    return 0;
}
