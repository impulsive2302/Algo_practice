#include<iostream>
using namespace std;
class minHeap
{
    int *harr;
    int capacity;
    int size;
public:
    minHeap(int cap)
    {
        size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    void MinHeapify(int );
    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void minHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && harr[l] < harr[i])
        smallest = l;
    if (r < size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void minHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    size++;
    int i = size-1;
    harr[i] =k;
    while(i!=0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[parent(i)],&harr[i]);
        i = parent(i);
    }
}
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void minHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
// Method to remove minimum element (or root) from min heap
int minHeap::extractMin()
{
    if(size == 0)
        return INT_MAX;
    if(size == 1)
    {
        size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[size-1];
    size--;
    MinHeapify(0);
    return root;
}
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void minHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
int main()
{
 minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
