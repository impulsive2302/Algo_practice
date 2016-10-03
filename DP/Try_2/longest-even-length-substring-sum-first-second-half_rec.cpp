#include<iostream>
#include <string.h>
using namespace std;
bool check_substring_sum(char str[], int start, int end)
{
    int len = end - start + 1;
    if(len <= 1)
        return 0;
    if(len%2 != 0)
        return 0;

    int lsum = 0;
    int rsum = 0;
    int mid = len/2;
    for(int i = start;i<=start+mid-1;i++)
    {
        lsum += (str[i] - '0');
    }
    for(int i = start + mid;i<=end;i++)
    {
        rsum += (str[i] - '0');
    }
    return (lsum == rsum);
}
int  findLengthUtil(char str[],int start, int end)
{
    if(start > end)
        return 0;
    if(check_substring_sum(str,start,end))
        return end-start+1;
    return max(findLengthUtil(str, start + 1,end), findLengthUtil(str,start,end-1));
}
findLength(char str[],int n)
{
    return findLengthUtil(str,0,n-1);
}
int main()
{
    char str[] = "123123";
    int len = strlen((const char*)str);
    cout<<"len = "<<len<<endl;
    printf("Length of the substring is %d", findLength(str, len));
    return 0;
}
