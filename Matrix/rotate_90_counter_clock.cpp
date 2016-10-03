// C++ program to rotate a matrix by 90 degrees
#include <bits/stdc++.h>
#define N 4
using namespace std;

void displayMatrix(int mat[N][N]);

// An Inplace function to rotate a N x N matrix
// by 90 degrees in anti-clockwise direction
void rotateMatrix(int mat[][N])
{
    for(int layer = 0;layer < N/2;layer++)
    {
        int first = layer;
        int last = N - layer - 1;
        for(int i = first; i < last; i++)
        {
            int offset = i - first;
            //COUNTER CLOCKWISE ROTATION
            int top = mat[first][i];
            // replace top with right element
            mat[first][i] = mat[i][last];
            //replace right with  bottom
            mat[i][last] = mat[last][last - offset];
            //replace bottom with  left
            mat[last][last - offset] = mat[last - offset][first];
            mat[last-offset][first] = top;

            /*
            // CLOCKWISE ROTATION
            int top = mat[first][i];
            mat[first][i] = mat[last-offset][first];
            mat[last-offset][first] = mat[last][last-offset];
            mat[last][last-offset] = mat[i][last];
            mat[i][last] = top;*/
        }
    }
}

// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}


/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };


    // Tese Case 2
    /* int mat[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
     */

    // Tese Case 3
    /*int mat[N][N] = {
                    {1, 2},
                    {4, 5}
                };*/

    //displayMatrix(mat);

    rotateMatrix(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}
