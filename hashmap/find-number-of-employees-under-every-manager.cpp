#include<iostream>
#include<map>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
map<string, int> result;
void populateResult(map<string,string> dataset)
{
    map<string,vector<string> > mgr_to_emp;
    map<string,string>:: iterator it;
    for(it = dataset.begin();it!=dataset.end();it++)
    {
        if(!(it->first).strcmp(it->second))
        {
            vector<string> emp;
            if(mgr_to_emp.find(it->second) == mgr_to_emp.end())
            {
                emp.push_back(it->first);
            } else {
                emp = mgr_to_emp.find(it->second);
                emp.push_back(it->first);
            }
            mgr_to_emp[it->second] = emp;
        }
    }
}
int main()
{
    map<string,string> dataset;
    dataset["A"] = "C";
    dataset["B"] = "C";
    dataset["C"] = "F";
    dataset["D"] = "E";
    dataset["E"] = "F";
    dataset["F"] = "F";
    populateResult(dataset);

    map<string,int>:: iterator it;
    for(it = result.begin();it!=result.end();it++)
        cout<<it->first<<"  "<<it->second<<endl;
}

