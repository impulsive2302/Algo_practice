#include <iostream>
using namespace std;
void selection_sort(int a[],int n)
{
    for(int i = 0;i < n-1;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void print_arr(int a[],int size)
{
    for(int i = 0; i<size;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}
int main()
{
    int a[] = {33,53,56,21,8,22,52,67,29};
    int size = sizeof(a)/sizeof(*a);
    print_arr(a,size);
    selection_sort(a,size);
    print_arr(a,size);
}

