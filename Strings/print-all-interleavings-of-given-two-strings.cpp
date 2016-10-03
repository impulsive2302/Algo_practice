#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
void printIlsrecursive(char* str1, char* str2, char* iStr, int m, int n, int i)
{
// Base case: If all characters of str1 and str2 have been
    // included in output string, then print the output string
    if (m==0 && n==0)
        printf("%s\n", iStr) ;

    // If some characters of str1 are left to be included, then
    // include the  first character from the remaining characters
    // and recur for rest
    if (m != 0)
    {
        iStr[i] = str1[0];
        printIlsrecursive (str1 + 1, str2, iStr, m-1, n, i+1);
    }

    // If some characters of str2 are left to be included, then
    // include the  first character from the remaining characters
    // and recur for rest
    if (n != 0)
    {
        iStr[i] = str2[0];
        printIlsrecursive(str1, str2+1, iStr, m, n-1, i+1);
    }
}
void printIls(char* str1, char* str2,int m,int n)
{
    char* result = (char*)malloc((m + n + 1) * sizeof(char*));
    result[m+n] = '\0';
    printIlsrecursive(str1,str2,result,m,n,0);
}
int main()
{
    char str1[] = "AB";
    char str2[] = "CD";
    printIls (str1, str2, strlen(str1), strlen(str2));
    return 0;
}
