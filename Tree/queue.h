#include <iostream>
using namespace std;

class queue
{
    int front,end;
    int arr[500];
public:
    queue()
    {
        front = 0;
        end = 0;
        //arr [500] = {0};
    }

    void enqueue(int val)
    {
        arr[end++] = val;
    }
    int dequeue()
    {
        if(end==front)
            return -1;
        return arr[front++];
    }
    void print_queue()
    {
        for(int i=front;i<end;i++)
        {
            cout<<arr[i]<<"    ";
        }
        cout<<endl;
    }
};
