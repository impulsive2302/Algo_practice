#include<iostream>
using namespace std;
#define MAX 256
struct charfreq{
    char c;
    int f;
};
// A utility function to swap two charFreq items.
void swap(charFreq *x, charFreq *y) {
    charFreq z = *x;
    *x = *y;
    *y = z;
}
void maxheapify(charFreq freq[], int i, int heapsize)
{
    int l =  2*i + 1;
    int r =  2*i + 2;
    int largest = i;
    if(freq[l].f > freq[i].f)
        largest = l;
    if(freq[r].f > freq[largest].f)
        largest = r;
    if(i!=largest)
    {
        swap(&freq[i], &freq[largest]);
        maxHeapify(freq, largest, heap_size);
    }
}
void buildHeap(charFreq freq[], int n)
{
    int i = (n-1)/2;
    while(i>0)
    {
        maxheapify(freq,i,n);
        i--;
    }
}
charfreq extractmax(charfreq freq[], int heap_size)
{
    charfreq maxe = freq[0];
    if(heap_size > 1)
    {
        freq[0] = freq[heapsize-1];
        maxheapify(freq,heap_size-1, heap_size);
    }
}
void rearrange(char* str)
{

}
int main()
{
    char str[] = "aabbcc";
    rearrange(str, 3);
    cout << str;
}
