#include<iostream>
using namespace std;
int mint(int x, int y,int z)
{
    return  min(min(x, y), z);
}
int editDistRecursive(string str1 , string str2 , int m ,int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0) return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0) return m;

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m-1] == str2[n-1])
        return editDist(str1, str2, m-1, n-1);

    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values.
    return 1 + min ( editDist(str1,  str2, m, n-1),    // Insert
                     editDist(str1,  str2, m-1, n),   // Remove
                     editDist(str1,  str2, m-1, n-1) // Replace
                   );
}
int editDist(string str1, string str2, int m, int n)
{
    int D[m+1][n+1];
    for(int i = 0;i<=m;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(i==0)
                D[i][j] = j;
            else if(j==0)
                D[i][j] = j;
            else if(str1[i-1] == str2[j-1])
                D[i][j] = D[i-1][j-1];
            else
                D[i][j] = 1 + mint(D[i-1][j],
                                   D[i][j-1],
                                   D[i-1][j-1]);
        }
    }
    return D[m][n];
}
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist( str1 , str2 , str1.length(), str2.length());

    return 0;
}

