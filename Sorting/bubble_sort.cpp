#include <iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
    bool swapped = true;
    for(int i = n-1; i >= 0 && swapped;i--)
    {
        swapped = false;
        for(int j = 0;j < i;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]  = temp;
                swapped = true;
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
    bubble_sort(a,size);
    print_arr(a,size);
}
