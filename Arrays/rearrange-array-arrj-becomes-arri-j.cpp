// A space efficient C program to rearrange contents of
//  arr[] such that arr[j] becomes j if arr[i] is j
#include<stdio.h>
#include<iostream>
using namespace std;
// A utility function to print contents of arr[0..n-1]
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// A space efficient method to rearrange 'arr[0..n-1]'
// so that 'arr[j]' becomes 'i' if 'arr[i]' is 'j'
void rearrange(int arr[], int n)
{
    for(int i = 0;i < n; i++)
    {
        int tempindex = arr[i];
        int temp = i;
        while(tempindex >= 0)
        {
            int temp2index = arr[tempindex];
            int temp2 = tempindex;
            if(temp == 0)
            {
                arr[tempindex] = -n;
            }
            else {
                arr[tempindex] = -temp;
            }
            temp = temp2;
            tempindex = temp2index;
        }
    }
    for(int i = 0;i<6; i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i = 0;i<6; i++)
    {
        if(arr[i] == -n)
            arr[i] = 0;
        else
            arr[i] = -arr[i];
    }
}

// Drive program
int main()
{
    int arr[] =  {2, 0, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    rearrange(arr,  n);

    printf("Modified array is \n");
    printArray(arr, n);
    return 0;
}
