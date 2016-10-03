#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

// Binary search
int GetCeilIndex(int A[], int T[], int l, int r, int key) {
   int m;

   while( r - l > 1 ) {
      m = l + (r - l)/2;
      if( A[T[m]] >= key )
         r = m;
      else
         l = m;
   }

   return r;
}

int LongestIncreasingSubsequence(int arr[], int size) {
   // Add boundary case, when array size is zero
   // Depend on smart pointers
   int tailindex[size];
   int previous[size];
   int len = 1;
   for(int i = 0;i < size;i++)
   {
        tailindex[i] = 0;
        previous[i] = -1;
   }

   for(int i = 1;i < size;i++)
   {
       if(arr[i] < previous[i])
            tailindex[0] = i;
       else if(arr[i] > previous[len - 1])
       {
            previous[i] = tailindex[len - 1];
            tailindex[len++] = i;
       } else {
            int pos = GetCeilIndex(arr, tailindex,0,len-1,arr[i]);
            previous[i] = tailindex[pos-1];
            tailindex[pos] = i;
       }
   }
   cout << "LIS of given input" << endl;
   for( int i = tailindex[len-1]; i >= 0; i = previous[i] )
      cout << arr[i] << "   ";
   cout << endl;
   return len;
}

int main() {
   int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
   int size = sizeof(A)/sizeof(A[0]);

   printf("LIS size %d\n", LongestIncreasingSubsequence(A, size));

   return 0;
}
