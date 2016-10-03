#include<iostream>
#include"Linked_List.h"
void is_palin(node** head, node* tail, bool *answer)
{
    if(tail == NULL)
        return;
    int t_val = tail->val;
    is_palin(head,tail->next,answer);
    if((*head)->val != t_val)
        *answer = false;
    *head = (*head)->next;
}
using namespace std;
int main()
{
    Linked_list l1;
    l1.Add_node(0);
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(1);
    l1.Add_node(0);
    l1.print_linked_list();
    bool answer = true;
    node* temp = l1.head;
    is_palin(&l1.head,l1.head,&answer);
    if(answer)
        cout<<"Linked List is a Palindrome\n";
    else
        cout<<"Linked List is not a Palindrome\n";
    l1.head = temp;
    l1.print_linked_list();
    return 0;
}
