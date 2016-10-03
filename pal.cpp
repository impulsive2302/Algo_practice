#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string str,int start, int end)
{
    while(start<=end)
    {
        if(str[start] == str[end])
        {
            start++;
            end--;
        }
        else
            break;
    }
    return (start > end ? true:false);
}
int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int palin_start = -1;
    for(int i = 0;i<len;i++)
    {
        if(is_palindrome(str,i,len-1))
        {
            palin_start = i;
            break;
        }
    }
    if(palin_start != -1)
    {
        for(int i = 0;i<palin_start;i++)
            cout<<str[i];
    } else {
        for(int i = 0;i<len;i++)
            cout<<str[i];
    }

    return 0;
}
