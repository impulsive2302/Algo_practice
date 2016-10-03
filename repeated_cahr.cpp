#include<iostream>
using namespace std;
void findRepeatCharacters(char *a) {
    int hash_map[256] = {0};
    for(int i=0;a[i]!='\0';i++)
    {
        hash_map[a[i]]++;
    }
    for(int i=0;i<256;i++)
    {
        if(hash_map[i]!=0)
            printf("%c\n",i);
    }

}
int main()
{
    char * str = "deeepaaakkk";
    findRepeatCharacters(str);
    return 0;
}
