#include<iostream>
using namespace std;
int main()
{
    int t;
    while(t--)
    {
        int n;
        cin>>n;
        int input[n];
        int ans = n;
        int window_element = input[0];
        for(int i = 1; i < n ;i++)
        {
            if(window_element == a[i])
                ans++;
            else {
                window_element = a[i];
            }
        }
    }
}
