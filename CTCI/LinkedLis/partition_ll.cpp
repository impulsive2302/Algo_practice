#include"Linked_List.h"
#include<iostream>
using namespace std;
void partition_list(node** head, int x)
{
    node* iterat = *head;
    while(iterat->next != NULL)
    {
        if(iterat->next->val < x ) {
            node* temp = iterat->next;
            iterat->next = iterat->next->next;
            temp->next = *head;
            *head = temp;
        } else
            iterat = iterat->next;
    }
}
int main()
{
    Linked_list l1;
    l1.Add_node(9);
    l1.Add_node(8);
    l1.Add_node(7);
    l1.Add_node(6);
    l1.Add_node(5);
    l1.Add_node(4);
    l1.Add_node(3);
    l1.Add_node(2);
    l1.Add_node(1);
    l1.Add_node(0);
    l1.print_linked_list();
    partition_list(&l1.head,5);
    l1.print_linked_list();
}
