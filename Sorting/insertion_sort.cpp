#include <iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    for(int i = 1;i< n;i++)
    {
        for(int j = i;j>0;j--)
        {
            if(a[j-1]>a[j])
            {
                int temp = a[j-1];
                a[j-1]= a[j];
                a[j]= temp;
            }
        }
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
    insertion_sort(a,size);
    print_arr(a,size);
}


