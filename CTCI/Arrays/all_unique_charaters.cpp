#include<iostream>
#include<string.h>
using namespace std;
bool is_unique(string str)
{
    bool hash_map[256] = {false};
    for(int i = 0;i < str.length();i++)
    {
        if(hash_map[str[i]]) {
            return false;
        }
        else
            hash_map[str[i]] = true;
    }
    return true;
}
int main()
{
    string str1 = "Deepakkushwah";
    string str2 = "abcdefghijkl";
    if(is_unique(str1))
        cout<<"str1 is unique"<<endl;
    else
        cout<<"str1 is not unique"<<endl;

    if(is_unique(str2))
        cout<<"str2 is unique"<<endl;
    else
        cout<<"str2 is not unique"<<endl;
    return 0;
}
