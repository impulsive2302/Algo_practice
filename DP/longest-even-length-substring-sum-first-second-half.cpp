#include<iostream>
using namespace std;

//NOT A DP SOLUTION
int findLength(string str,int n)
{
    int ans = 0;
    for(int i = 0;i<=n-2;i++)
    {
        int l = i;
        int r = i+1;
        int lsum =0;
        int rsum =0;
        while(l>=0 && r<n)
        {
            lsum += str[l] - '0';
            rsum += str[r] - '0';
            if(lsum == rsum)
                ans = max(ans,r-l+1);
            l--;r++;
        }
    }
    return ans;
}

int main()
{
    string str = "123123";
    cout << "Length of the substring is " << findLength(str, str.length());
    return 0;
}
