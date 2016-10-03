#include<iostream>
#include<cstdlib>
using namespace std;
#define ROW 4
#define COLUMN 5
int main()
{
    int** a = (int**) malloc(ROW * (sizeof(int*)));
    for(int i = 0;i<ROW;i++)
        a[i] = (int *) malloc(sizeof(int) * COLUMN);
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COLUMN;j++)
        {
            a[i][j] = i+j;
        }
    }
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COLUMN;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
}
