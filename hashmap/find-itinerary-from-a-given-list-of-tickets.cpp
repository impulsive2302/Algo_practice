#include<iostream>
#include<map>
using namespace std;
void printItinerary(map<string,string> dataset)
{
    map<string,string> reverse_data;
    map<string,string>::iterator it;
    for(it = dataset.begin();it!=dataset.end();it++)
        reverse_data[it->second] = it->first;
    string start;
    for(it = dataset.begin();it!=dataset.end();it++)
    {
        if(reverse_data.find(it->first) == reverse_data.end())
        {
            start = it->first;
            break;
        }
    }
    if (start.empty())
     {
        cout << "Invalid Input" << endl;
        return;
     }
     it = dataset.find(start);
     while(it!=dataset.end())
     {
        cout << it->first << "->" << it->second << endl;
        it = dataset.find(it->second);
     }
}
int main()
{
    map<string ,string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";

    printItinerary(dataSet);

    return 0;
}
