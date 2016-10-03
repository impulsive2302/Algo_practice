# include <iostream>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSum(int arr[], int n, int x)
{
     int min_len = n + 1;
     int window_sum = 0;
     int start =0;
     int end=0;
     for(int i =0;i<n;i++)
     {
         //cout<<"processing "<<arr[i]<<endl;
         window_sum += arr[i];
         if(window_sum > x)
         {
             end = i;
             min_len = min(min_len, end-start+1);
             //cout<<"found sum = "<<window_sum<<" greater than "<<x <<" now start srinking the window from "<<start<<"  with length "<<min_len<<endl;
             for(int j = start; j<=end; j++)
             {
                 //cout <<"check Shrinking for "<<arr[j]<<endl;
                 window_sum -= arr[j];
                 //cout <<"window sum after removing  "<<arr[j]<<"  is  "<<window_sum<<endl;
                 start++;
                 if(window_sum > x)
                    min_len = min(min_len, end-start+1);
                 //cout<<"min_len updated = "<<min_len<<endl;
                 if(window_sum < x)
                    break;
             }
         }
     }
     return min_len;
}

/* Driver program to test above function */
int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << smallestSubWithSum(arr1, n1, x) << endl;
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    cout << smallestSubWithSum(arr2, n2, x) << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    cout << smallestSubWithSum(arr3, n3, x);
    return 0;
}
