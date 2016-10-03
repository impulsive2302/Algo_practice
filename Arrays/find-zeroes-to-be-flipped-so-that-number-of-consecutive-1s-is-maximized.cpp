// C++ program to find positions of zeroes flipping which
// produces maximum number of xonsecutive 1's
#include<bits/stdc++.h>
using namespace std;

// m is maximum of number zeroes allowed to flip
// n is size of array
void findZeroes(int arr[], int n, int m)
{
    for(int i =0;i<n;i++)
    {
        if(arr[i] == 0)
            arr[i] = 1;
        else arr[i] = 0;
    }

    int start = 0;int end = 0;
    int window = 0;
    int onecount = 0;
    int max = 0;
    int curr_window_start = 0;
    for(int i = 0;i < n;i++)
     {
        if(arr[i] == 1)
        {
            window++;
            onecount++;
            if(onecount <= m)
                end = i;
            if(onecount > m) {
                for(int j = curr_window_start;j < i; j++){
                    window--;
                    if(arr[j] == 1)
                    {
                        onecount--;
                        if(onecount == m)
                        {
                            curr_window_start = j+1;
                            break;
                        }
                    }
                }
            }
        } else {
            window++;
            if(window > max) {
                start = curr_window_start;
                max = window;
                end = i;
            }
        }
     }
     for(int i = start ;i<=end;i++)
     {
         if(arr[i] == 1)
            cout<<endl<<i;
     }
     cout<<endl;
    for(int i =0;i<n;i++)
    {
        if(arr[i] == 0)
            arr[i] = 1;
        else arr[i] = 0;
    }
}

// Driver program
int main()
{
   int arr[] = {0,0,0,0,0,0};
   int m = 2;
   int n =  sizeof(arr)/sizeof(arr[0]);
   cout << "Indexes of zeroes to be flipped are ";
   findZeroes(arr, n, m);
   return 0;
}
