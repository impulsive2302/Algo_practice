#include<iostream>
using namespace std;
string reverse_string(string str)
{
    int start = 0;
    int end = str.length()-1;
    while(start<end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}
int main()
{
    string str = "Deepak";
    cout<<reverse_string(str);
}
