#include<iostream>
#include <string.h>
using namespace std;
string remove_duplicate(char* str)
{
    int hash_array[256] = {0};
    int ip_index = 0;
    int res_index = 0;
    while(*(str + ip_index))
    {
        if(hash_array[*(str + ip_index)] == 0)
        {
            *(str + res_index) = *(str + ip_index);
            hash_array[*(str + ip_index)]++;
            res_index++;
        }
        ip_index++;
    }
    *(str + res_index) = '\0';

  return str;
}
int main()
{
    char str[] = "Deepakkushwah";
    cout<<str<<endl;
    cout<<remove_duplicate(str);

}
