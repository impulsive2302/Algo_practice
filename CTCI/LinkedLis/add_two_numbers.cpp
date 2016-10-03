#include<iostream>
#include"Linked_List.h"
node* add_linked_list_number(node*  head1, node* head2, int carry)
{
    if(head1 == NULL && head2 == NULL && carry == 0)
    {
        return NULL;
    }
    node* new_node = new node;
    new_node->next = NULL;
    int value = carry;
    if(head1 != NULL)
        value += head1->val;
    if(head2 != NULL)
        value += head2->val;
    new_node->val = value % 10;
    if(head1 != NULL || head2 != NULL) {
        node* next_node = add_linked_list_number(head1 == NULL ? NULL : head1->next,
                                                 head2 == NULL ? NULL : head2->next,
                                                 value >= 10 ? 1 : 0);
        new_node->next = next_node;
    }
    return new_node;
}
using namespace std;
int main()
{
    Linked_list l1;
    Linked_list l2;
    l1.Add_node(6);
    l1.Add_node(1);
    l1.Add_node(7);
    l1.Add_node(3);
    l1.print_linked_list();
    l2.Add_node(2);
    l2.Add_node(9);
    l2.Add_node(5);
    l2.print_linked_list();
    Linked_list l3;
    l3.head = add_linked_list_number(l1.head,l2.head,0);
    l3.print_linked_list();
}
