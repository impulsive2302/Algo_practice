// C/C++ program to remove all adjacent duplicates
// from a string
#include <iostream>
#include <string.h>
using namespace std;

// This function recursively removes duplicates
// and returns modified string
char* stringFilter(char * str)
{
    int res = 0;
    for(int i = 0;*(str+i) ;i++)
    {
       // cout<<"processing "<<str[i]<<" at index "<<i<<endl;
        if(*(str + i) == 'b')
            continue;
        else if(*(str+i+1))
        {
            if(*(str + i) == 'a' && *(str + i + 1) == 'c')
            {
                //cout<<"found ac"<<endl;
                i++;
            }
            else {
                //cout<<"copying "<<str[i]<<" at index "<<res<<" From index "<<i<<endl;
                *(str + res) = *(str + i);
                res++;
            }
        } else {
         *(str + res) = *(str + i);
                res++;
        }
    }
    *(str + res) = '\0';
}

int main()
{
    char str1[] = "aacacc";
    stringFilter(str1);
    cout << str1 << endl;

    return 0;
}
// This code is contributed by Aditya Goel.
