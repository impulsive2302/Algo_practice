#include<iostream>
using namespace std;
int maxProfit(int arr[],int n)
{
    int profit[n] = {0};
    int max1 = arr[n-1];
    for(int i = n-2;i>=0;i--)
    {
        if(max1 < arr[i])
            max1 = arr[i];
        profit[i] = max(profit[i+1],max1 - arr[i]);
    }
    int min = arr[0];
    for(int i = 1;i<n;i++)
    {
        if(min > arr[i])
            min = arr[i];
        profit[i] = max(profit[i-1],profit[i] + arr[i]-min);
    }
    return profit[n-1];
}
int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}

