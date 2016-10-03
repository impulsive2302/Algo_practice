#include<iostream>
using namespace std;

void reorder(int arr[],int index[],int n)
{
    for(int i = 0;i < n;i++)
    {
        int curr_index = i;
        int dest_index = index[i];
        //cout<<"new"<<endl;
        while(curr_index != dest_index)
        {
            //cout<<"curr index = "<<curr_index<<endl;
            //cout<<"dest index = "<<dest_index<<endl;

            //swap values and indexes with current and destination
            int temp = arr[curr_index];
            arr[curr_index] = arr[dest_index];
            arr[dest_index] = temp;

            temp = index[curr_index];
            index[curr_index] = index[dest_index];
            index[dest_index] = temp;

            //curr_index = dest_index;
            dest_index = index[curr_index];
            //cout<<"After curr index = "<<curr_index<<endl;
            //cout<<"After dest index = "<<dest_index<<endl;
        }
    }
}
int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);

    reorder(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}
