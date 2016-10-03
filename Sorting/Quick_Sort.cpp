#include <iostream>
using namespace std;
void swap_qick(int *a1,int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
int partition_array_based_on_pivot(int a[],int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for(int i = start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap_qick(&a[i],&a[pIndex]);
            pIndex++;
        }
    }
    swap_qick(&a[pIndex],&a[end]);
    return pIndex;
}

void quick_sort(int a[],int start, int end)
{
    if(start < end)
    {
        int final_index = partition_array_based_on_pivot(a,start,end);
        quick_sort(a,start,final_index-1);
        quick_sort(a,final_index+1,end);
    }
    else
        return;
}

void print_arr(int a[],int size)
{
    for(int i = 0; i<size;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}
int main()
{
    int a[] = {7,2,1,6,8,5,3,4};
    int size = sizeof(a)/sizeof(*a);
    cout<<"Original Array:"<<endl;
    print_arr(a,size);
    quick_sort(a,0, size-1);
    cout<<"Sorted Array:"<<endl;
    print_arr(a,size);
}
