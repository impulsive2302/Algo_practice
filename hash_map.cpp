#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,int> m;
    m[-1] = 11;
    m[-4] = 43;
    m[1] = 22;
    m[5] = 44;
    m[6] = 65;
    for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    cout<<endl<<"Deepak"<<m.count(333);
    cout<<endl<<"Deepak"<<m.count(1);
    return 0;

}
