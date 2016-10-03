#include<iostream>
using  namespace std;
int main()
{
	int n;
	cin>>n;
	int mat[n][n];
	for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    for (int slice = 0; slice < 2 * n - 1; ++slice) {
    	int z = slice < n ? 0 : slice - n + 1;
    	for (int j = z; j <= slice - z; ++j) {
    		printf("%d ", mat[j][slice - j]);
    	}
    }
}

