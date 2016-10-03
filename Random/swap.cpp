#include <iostream>
using namespace std;
void swap_qick(int *a1,int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
int main()
{
    int a = 2;
    int b =3;
    cout<<"before swap"<<a <<"  "<<b<<endl;
    swap_qick(&a,&b);
    cout<<"after swap"<<a <<"  "<<b<<endl;
}
