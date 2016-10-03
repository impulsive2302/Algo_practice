#include<iostream>
#include <string.h>
using namespace std;
longestCommonSum(bool arr1[],bool arr2[],int n)
{
    int presum1 = 0;
    int presum2 = 0;
    int diffarr[2*n+1];
    int maxlen = 0;
    for(int j =0;j<2*n+1;j++)
        diffarr[j] = -1;
    for(int i = 0;i < n;i++)
    {
        presum1 +=arr1[i];
        presum2 +=arr2[i];
        int diff = presum1 - presum2;
        int diffindex = n + diff;
        if(diff == 0)
            maxlen = i+1;
        else if(diffarr[diffindex] == -1)
        {
            diffarr[diffindex] = i;
        } else {
            int local_max = i-diffarr[diffindex];
            if(local_max > maxlen)
                maxlen = local_max;
        }
    }
    return maxlen;
}
int main()
{
    bool  arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool  arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Length of the longest common span with same "
            "sum is "<< longestCommonSum(arr1, arr2, n);
    return 0;
}
