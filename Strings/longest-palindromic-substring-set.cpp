#include<iostream>
#include<string.h>
using namespace std;
int longestPalSubstr(char* str)
{
    int maxlen = 0;
    int len = strlen(str);
    for(int i = 1;i < len;i++)
    {
        //check for even length palindrome
        int high = i;
        int low = i-1;
        while(high<len && low>=0 && str[high] == str[low])
        {
            if(maxlen < (high - low + 1))
                maxlen = high - low + 1;
            --low;
            ++high;
        }
        // check for odd length palindrome
        high = i+1;
        low = i-1;
        while(high<len && low>=0 && str[high] == str[low])
        {
            if(maxlen < (high - low + 1))
                maxlen = high - low + 1;
            --low;
            ++high;
        }
    }

    return maxlen;
}
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longestPalSubstr(str));
    return 0;
}
