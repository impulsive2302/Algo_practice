#include<iostream>
using namespace std;
bool  is_integer_palindrome(int n)
{
    int rev = 0;
    int m = n;
    while(n)
    {
        int rem =n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return (rev == m);
}
int main()
{
    int a = 12221;
    if(is_integer_palindrome(a))
        cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
