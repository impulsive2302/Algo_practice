#include <stdio.h>
#define R 6
#define C 4
// The main function that returns index of row with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    int i = 0;
    int j = C-1;
    int row = -1;
    int max_one = 0;
    while(i<R)
    {
        while(mat[i][j] == 1 && j >= 0)
        {
            max_one++;
            row = i;
            j--;
        }
        i++;
    }
    return row;
}

/* Driver program to test above functions */
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 1}
    };

    printf("Index of row with maximum 1s is %d \n", rowWithMax1s(mat));

    return 0;
}
