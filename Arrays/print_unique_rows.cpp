//Given a binary matrix of M X N of integers, you need to return only unique rows of binary array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 4
#define COL 5

// A Trie node
typedef struct Node
{
    bool isEndOfCol;
    struct Node *child[2]; // Only two children needed for 0 and 1
} Node;


// A utility function to allocate memory for a new Trie node
Node* newNode()
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->isEndOfCol = false;
    temp->child[0] = NULL;
    temp->child[1] = NULL;
    return temp;
}

// Inserts a new matrix row to Trie.  If row is already
// present, then returns 0, otherwise insets the row and
// return 1
bool insert( Node** root, int (*M)[COL], int row, int col )
{
    if(!*root)
        *root = newNode();
    if(col < COL)
    {
        return insert(&((*root)->child[M[row][col]]),M,row,col+1);
    } else {
        if(!(*root)->isEndOfCol)
        {
            (*root)->isEndOfCol = 1;
            return 1;
        }
        else return 0;
    }

}

// A utility function to print a row
void printRow( int (*M)[COL], int row )
{
    int i;
    for( i = 0; i < COL; ++i )
        printf( "%d ", M[row][i] );
    printf("\n");
}

// The main function that prints all unique rows in a
// given matrix.
void findUniqueRows( int M[ROW][COL] )
{
    Node* root = NULL; // create an empty Trie
    int i;

    // Iterate through all rows
    for ( i = 0; i < ROW; ++i )
        // insert row to TRIE
        if ( insert(&root, M, i, 0) )
            // unique row found, print it
            printRow( M, i );
}

// Driver program to test above functions
int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };

    findUniqueRows( M );

    return 0;
}
