#include<iostream>
#include<algorithm>
using namespace std;
struct job{
    int start;
    int finish;
    int weight;
};
bool jobComparataor(job s1, job s2)
{
    return s1.finish < s2.finish;
}
bool are_jobs_colliding(job arr[],int i,int j)
{
    //i to be compared with
    //j is the next starting one
    return (arr[i].finish > arr[j].start);
}
int max_profit(job arr[],int n)
{
    sort(arr,arr+n,jobComparataor);
    cout<<endl<<"after sorting"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout << arr[i].finish<<"    ";
    }
    cout<<endl;
    int weight_arr[n];
    for(int i =0;i<n;i++)
        weight_arr[i] = arr[i].weight;
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(!are_jobs_colliding(arr,j,i))
            {
                weight_arr[i] = max(weight_arr[i], weight_arr[j] + arr[i].weight);
            }
        }
    }
    int max = 0;
    for(int i =0;i<n;i++) {
        if(max < weight_arr[i])
            max = weight_arr[i];
    }
    return max;
}
int main()
{
    job arr[] = {{3, 10, 20},{1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<len;i++)
    {
        cout << arr[i].finish<<"    ";
    }
    cout<<endl;
    cout<<endl;
    cout << max_profit(arr,len);
    cout<<endl;
    cout<<endl;
}
