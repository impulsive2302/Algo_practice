#include<iostream>
using namespace std;
int count_bits(int a, int b)
{
    int xorw = a^b;
    int count = 0;
    while(xorw)
    {
        if(xorw & 0x1){
            count++;
            cout<<"hi"<<endl;;
        }
        xorw = xorw>>1;
    }
    return count;
}
int main()
{
    cout <<count_bits(73,21)<<endl;
}
