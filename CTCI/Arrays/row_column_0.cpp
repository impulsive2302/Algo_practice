#include <stdio.h>
#define R 3
#define C 4
#include<iostream>
using namespace std;
void modifyMatrix(bool mat[R][C])
{
    bool row_one = false;
    bool column_one = false;
    for(int i = 0;i < C; i++)
    {
        if(mat[0][i] == 1)
            row_one = true;
    }
    for(int i = 0;i < R; i++)
    {
        if(mat[i][0] == 1)
            column_one = true;
    }
    for(int i = 1;i < R; i++)
    {
        for(int j = 1;j < C;j++)
        {
            if(mat[i][j] == 1)
            {
                mat[i][0] = 1;
                mat[0][j] = 1;
            }
        }
    }
    for(int i = 0;i<C;i++)
    {
        if(mat[0][i] == 1)
        {
            for(int j = 0;j<R;j++)
            {
                mat[j][i] = 1;
            }
        }
    }
    for(int i = 0;i<R;i++)
    {
        cout<<"mat["<<i<<"][0]"<<mat[i][0]<<endl;
        if(mat[i][0] == 1)
        {
            for(int j = 0;j < C;j++)
            {
                cout<<i <<" "<<j<<endl;
                mat[i][j] = 1;
            }
        }
    }
    if(row_one)
    {
        for(int i = 0;i<R;i++)
        {
            mat[0][i] = 1;
        }
    }
    if(column_one)
    {
        for(int i = 0;i < C;i++)
        {
            mat[i][0] = 1;
        }
    }
}

/* A utility function to print a 2D matrix */
void printMatrix(bool mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{
    bool mat[R][C] = { {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };

    printf("Input Matrix \n");
    printMatrix(mat);

    modifyMatrix(mat);

    printf("Matrix after modification \n");
    printMatrix(mat);

    return 0;
}
