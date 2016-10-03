// A O(n) program to find the largest subarray with equal number of 0s and 1s
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
// A utility function to get maximum of two integers
int max(int a, int b) { return a>b? a: b; }

// This function Prints the starting and ending indexes of the largest subarray
// with equal number of 0s and 1s. Also returns the size of such subarray.
int findSubArray(int arr[], int n)
{
    int prefix[n]={0};
    int pre = 0;
    for(int i = 0 ;i<n;i++) {
        pre += arr[i];
        prefix[i] = pre;
    }
    for(int i = 0 ;i<n;i++) {
        //cout<<prefix[i]<<"  ";
    }
    cout<<endl;
    int l =0;
    int r = n-1;
    int len = -1;
    while(l < r)
    {
        int onecount;
        int sizearr = -1;
        //cout << "l = "<<l <<"  r =  "<<r<<endl;
        if(arr[l] == 1)
        {
            onecount = prefix[r] - prefix[l] + 1;
        }else {
            onecount = prefix[r] - prefix[l];
        }
        sizearr = r - l + 1;
        //cout << "onecount = "<<onecount <<"  sizearr =  "<<sizearr<<endl;
        if((2 * onecount) == sizearr){
            len = sizearr;
            break;
        } else if((2 * onecount) > sizearr){
            if(arr[r] == 1)
                r--;
            else l++;
        } else if((2 * onecount) < sizearr){
            if(arr[r] == 0)
                r--;
            else l++;
        }
    }
    if(len == -1)
        cout<<"No such array";
    else
        cout<<l<<"     to     "<<r<<endl;;
    return len;
}

/* Driver program to test above functions */
int main()
{
    int arr[] =  {1, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    findSubArray(arr, size);
    return 0;
}
