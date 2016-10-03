#include"Linked_List.h"
using namespace  std;
node* reverse_ll(node* head, node* next_node,node** new_head)
{
    if(next_node->next!=NULL)
    {
        reverse_ll(head->next,next_node->next, new_head);
    } else {
        *new_head = next_node;
        cout<<"Assigning new head = "<<(*new_head)->val<<endl;
    }
    next_node->next = head;
    return *new_head;
}
int main()
{
    Linked_list l1;
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.Add_node(4);
    l1.Add_node(5);
    l1.print_linked_list();
    node* temp_head = NULL;
    node* temp_head2 = NULL;
    if(l1.head->next!=NULL) {
        temp_head2 = reverse_ll(l1.head,l1.head->next,&temp_head);
        l1.head->next = NULL;
        l1.head = temp_head2;
    }
    l1.print_linked_list();
}
