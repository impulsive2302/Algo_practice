#include<iostream>
#include <string.h>
using namespace std;
string remove_duplicate(string str)
{
    int hash_str[256] = {0};
    int len = str.length();
    int original_index = 0;
    int final_index = 0;
    while(len>0)
    {
        char temp = str[original_index];
       // cout<<"character  found"<<temp<<endl;
        if(hash_str[temp] == 0 )
        {
           // cout<<"New character"<<endl;
            hash_str[temp] = 1;
            str[final_index] = str[original_index];
            final_index++;
        } else {
            //cout<<"character already present"<<endl;
        }
        original_index++;
        len--;
    }
    str[final_index] = '\0';
    return str;
}
int main()
{
    string str = "Deepakkushwah";
    cout<<str<<endl;
    str = remove_duplicate(str);
    cout<<str.c_str()<<endl;
}
