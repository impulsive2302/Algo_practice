#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void reverse_util(char* str, int len,int act_len)
{
    if(len == 0)
        return;
    //printf("called for len = %d\n",len);
    len--;
    reverse_util(str,len,act_len);
    //printf("len = %d act_len = %d\n",len,act_len);
    printf("%c",str[act_len-len-1]);
}
int reverse(char* str)
{
    int sizes = strlen(str);
    reverse_util(str,sizes,sizes);
}
int main()
{
   char a[] = "DEEPAK";
   reverse(a);
   return 0;
}
