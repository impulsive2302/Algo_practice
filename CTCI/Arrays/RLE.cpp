#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
char* RLE(char* str)
{
    char count[50];
    int len = strlen(str);
    char* dest = (char*)malloc(sizeof(char)*(len* 2 + 1));
    int index = 0;
    for(int i = 0;i < len;i++)
    {
        dest[index++] = str[i];
        int rlen = 1;
        while(((i+1) < len) && str[i] == str[i+1]){
            rlen++;
            i++;
        }
        sprintf(count,"%d",rlen);
        for(int k = 0;*(count + k);index++,k++)
            dest[index] = count[k];
    }
    dest[index] = '\0';
    return dest;
}
int main()
{
    char* str = "aabbbcddeeeee";
    cout<<RLE(str)<<endl;
}
