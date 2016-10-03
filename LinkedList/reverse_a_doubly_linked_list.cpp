#include"Double_Linked_List.h"
using namespace  std;
node* reverse_dll(node* head)
{
    if(!head || !head->next)
        return head;
    node* temp_prev = head;
    node* temp_next = head->next;
    while(temp_next->next!=NULL)
    {
        node* next_node = temp_next->next;
        temp_next->next = temp_prev;
        //cout<<"temp_next temp_next->next = "<<temp_next->val<<temp_next->next->val<<endl;
        temp_prev->previous = temp_next;
        temp_prev = temp_next;
        temp_next = next_node;
    }
    temp_next->next = temp_prev;
    temp_prev->previous = temp_next;
    temp_next->previous = NULL;
    head->next = NULL;
    //cout<<"making head to"<<temp_next->val<<endl;
    head = temp_next;
    return head;
}
int main()
{
    double_linked_list dll;
    dll.insert_node(1);
    dll.insert_node(2);
    dll.insert_node(3);
    dll.insert_node(4);
    dll.insert_node(5);
    dll.insert_node(6);
    dll.insert_node(7);
    dll.print_linked_list();
    dll.head = reverse_dll(dll.head);
    dll.print_linked_list();
}
