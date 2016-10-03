#include"Linked_List.h"
using namespace  std;
void pair_wise_swap(node* head)
{
    if(!head)
        return;
    node* temp_next = head->next;
    node* temp_prev = head;
    while(temp_next!=NULL && temp_next->next!=NULL)
    {
        //cout<<"inside while"<<endl<<endl;
        int temp_val = temp_next->val;
        //cout<<"Before Switching values" <<temp_prev->val<<"     "<<temp_next->val<<endl;
        temp_next->val = temp_prev->val;
        temp_prev->val = temp_val;
        //cout<<"After Switching values" <<temp_prev->val<<"     "<<temp_next->val<<endl;
        if(temp_next->next)
            temp_next = temp_next->next->next;
        if(temp_prev->next)
            temp_prev = temp_prev->next->next;
    }
    if(temp_next!=NULL)
    {
        int temp_val = temp_next->val;
        //cout<<"Before Switching values" <<temp_prev->val<<"     "<<temp_next->val<<endl;
        temp_next->val = temp_prev->val;
        temp_prev->val = temp_val;
    }
}
int main()
{
    Linked_list l;
    l.Add_node(1);
    l.Add_node(2);
    l.Add_node(3);
    l.Add_node(4);
    l.Add_node(5);
    l.Add_node(6);
    l.Add_node(7);
    l.print_linked_list();
    pair_wise_swap(l.head);
    l.print_linked_list();
    return 0;
}
