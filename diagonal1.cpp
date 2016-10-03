
#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;

bool isvalid(int i, int j)
{
    if (i < 0 || i >= R || j >= C || j < 0) return false;
    return true;
}

void diagonalOrder(int arr[][C])
{
    /* through this for loop we choose each element of first column
    as starting point and print diagonal starting at it.
    arr[0][0], arr[1][0]....arr[R-1][0] are all starting points */
    for (int k = 0; k < R; k++)
    {
        cout << arr[k][0] << " ";
        int i = k-1;    // set row index for next point in diagonal
        int j = 1;      //  set column index for next point in diagonal

        /* Print Diagonally upward */
        while (isvalid(i,j))
        {
            cout << arr[i][j] << " ";
            i--;
            j++;    // move in upright direction
        }

    }

    /* through this for loop we choose each element of last row
       as starting point (except the [0][c-1] it has already been
       processed in previous for loop) and print diagonal starting at it.
       arr[R-1][0], arr[R-1][1]....arr[R-1][c-1] are all starting points */

    //Note : we start from k = 1 to C-1;
    for (int k = 1; k < C; k++)
    {
        cout << arr[R-1][k] << " ";
        int i = R-2; // set row index for next point in diagonal
        int j = k+1; // set column index for next point in diagonal

        /* Print Diagonally upward */
        while (isvalid(i,j))
        {
            cout << arr[i][j] << " ";
            i--;
            j++; // move in upright direction
        }

    }
}

// Driver program to test above
int main()
{

    int arr[][C] = {{11, 12, 13},
        {15, 16, 17},
        {19,20,21},
    };
    diagonalOrder(arr);
    return 0;
}