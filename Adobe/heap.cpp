const int HEAP_SIZE=50;
#define PARENT(i)  (i-1)>>1
#define LEFT(x) 2*x+1 // since we start with index 0
#define RIGHT(x) 2*x+2

class MaxHeap
{
    int arr[HEAP_SIZE];
    int count;


public:
    MaxHeap()
    {
        count=0;
    }

    bool insert(int element);

    bool remove(int& element);

    bool increase_element(int element, int idx);

    bool decrease_element(int element, int idx);

    bool change(int element, int idx);
};
bool Maxheap::void max_Heapify(int a[],int i,int n){

    int largest=0;
    int l=left(i);
    int r=right(i);
    if(l<=n && a[l]>a[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r< n && a[r]>a[largest]){
        largest=r;
    }
    if (largest!=i){
        int t=a[i];
        a[i]=a[largest];
        a[largest]=t;
    }
    max_Heapify(largest);
}

bool MaxHeap::insert(int element)
{
    if(count > HEAP_SIZE)
        return false;

    int i = count;

    arr[i] = element;
    // the below loop never runs if the input
    // array is already in maxheap format!!
    while(i>0 && arr[PARENT(i)] < arr[i]) {
        int tmp=arr[PARENT(i)];
        arr[PARENT(i)] = arr[i];
        arr[i] = tmp;
        i = PARENT(i);
    }
    count++;
    return true;
}

bool MaxHeap::remove(int& element)
{
    if(count < 0)
        return false;

    element = arr[0];
    arr[0] = arr[count-1];
    arr[count-1] = INT_MIN;
    count = count - 1;
    max_heapify(arr, 0, count);
    return true;
}

bool MaxHeap::increase_element(int element, int idx)
{
    if(idx > count || idx < 0)
        return false;

    if(arr[idx] > element)
        return false;

    arr[idx] = element;

    // the below code is same as insert
    // repeating it, to be clear
    while(idx > 0 && arr[PARENT(idx)] < arr[idx]) {
        int tmp=arr[PARENT(idx)];
        arr[PARENT(idx)] = arr[idx];
        arr[idx] = tmp;
        idx = PARENT(idx);
    }
    return true;
}

bool MaxHeap::decrease_element(int element, int idx)
{
    if(idx > count || idx < 0)
        return false;

    if(element > arr[idx])
        return false;

    arr[idx]= element;
    max_heapify(arr, idx, count);
    return true;
}

bool MaxHeap::change(int element, int idx)
{
    if(idx > count || idx < 0)
        return false;

    if(element > arr[idx] )
        return increase_element(element, idx);
    else
        return decrease_element(element, idx);
}


void main()
{
    MaxHeap obj;
    int A[] = {7,2,1,12,15,8,4,0,6,13,9,5};

    for(int i=0; i<12;i++) {
        obj.insert(A[i]);
    }
    int val;
    obj.remove(val);
    obj.increase_element(20, 5);
    obj.decrease_element(3, 0);

    obj.change(80, 8);
    obj.change(0, 0);

}
