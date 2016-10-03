#include<iostream>
#include<string.h>
using namespace std;
#define R 3
#define C 14
int x[] = {-1,-1,1,1,0,0,-1,1};
int y[] = {-1,0,0,1,-1,1,1,-1};
bool patternSearchutil(char grid[R][C],int m,int n,string pattern)
{
    if(grid[m][n] != pattern[0])
        return false;
    int len = pattern.length();
    for(int i=0;i<8;i++)
    {
        int j;
        int rd = m + x[i];
        int cd = n + y[i];
        for( j = 1;j<len;j++)
        {
            if(rd >= R || cd >=C || rd < 0 || cd < 0)
                break;
            if(grid[rd][cd] != pattern[j])
                break;
            rd +=x[i];
            cd +=y[i];
        }
        if(j == len)
            return true;
    }
    return false;
}
void patternSearch(char grid[R][C], string pattern)
{
    for(int i =0;i<R;i++)
    {
        for(int j =0;j<C;j++)
        {
            if(patternSearchutil(grid,i,j,pattern))
                cout<<"pattern found at "<<i<<" "<<j<<endl;
        }
    }
}
int main()
{
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                      };

    patternSearch(grid, "GEEKS");
    cout << endl;
    cout << endl;
    patternSearch(grid, "EEE");
    return 0;
}
