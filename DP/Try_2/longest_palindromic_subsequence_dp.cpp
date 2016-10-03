
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq,int n)
{
    int table[n][n];
    for(int i = 0;i<n;i++)
        table[i][i] = 1;
    for(int cl = 2;cl<=n;cl++)
    {
        for(int i = 0;i<n-cl+1;i++)
        {
            int j = i+cl-1;
            if(seq[i] == seq[j] && cl == 2)
                table[i][j] = 2;
            else if(seq[i] == seq[j])
                table[i][j] = 2 + table[i+1][j-1];
            else
                table[i][j] = max(table[i][j-1],table[i+1][j]);
        }
    }
    return table[0][n-1];
}

/* Driver program to test above functions */
int main()
{
    char seq[] = "BBABCBCAB";
    int n = strlen(seq);
    printf ("The length of the LPS is %d", lps(seq, n));
    getchar();
    return 0;
}
