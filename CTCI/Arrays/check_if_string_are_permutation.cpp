#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    string str1 = "Deepakkushwah";
    string str2 = "Depaeakukshwha";
    int map_hash[256] = {0};
    for(int i = 0;i<str1.length();i++)
        map_hash[str1[i]]++;
    for(int i = 0;i<str2.length();i++)
        if(--map_hash[str2[i]] < 0) {
            cout<<"Not permutation";
            return 0;
        }
    cout<<"Permutation";
    return 0;
}
