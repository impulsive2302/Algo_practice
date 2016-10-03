#include "queue.h"
using namespace std;

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    cout<<"Popped "<<q.dequeue()<<endl; q.print_queue();
    return 0;
}
