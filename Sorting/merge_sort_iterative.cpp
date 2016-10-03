#include <iostream>
using namespace std;
int min(int x, int y) { return (x<y)? x :y; }

void merge_arr(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1];int R[n2];
 /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k++] = L[i++];
    }
    while(j<n2)
    {
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[],int n)
{
    int curr_size;
    int left_start;
    for(curr_size = 1;curr_size<=n-1;curr_size=2*curr_size)
    {
        for(int left_start=0;left_start<n-1;left_start+=2*curr_size)
        {
            int mid = left_start + curr_size -1;
            int right_end = min(left_start + 2*curr_size-1,n-1);
            merge_arr(arr, left_start, mid, right_end);
        }
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, arr_size);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}



