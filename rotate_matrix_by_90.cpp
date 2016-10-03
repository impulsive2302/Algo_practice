#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int j = 0;j<n;j++)
    {
        for(int i = m-1;i>=0;i--)
        {
            {
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
}
