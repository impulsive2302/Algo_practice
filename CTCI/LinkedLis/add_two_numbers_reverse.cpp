#include<iostream>
#include"Linked_List.h"
using namespace std;
node* add_linked_list_number(node*  head1, node* head2, int* carry)
{
    if(head1 == NULL && head2 == NULL)
        return NULL;
    node* temp1 = add_linked_list_number(head1->next,head2->next,carry);
    node* new_node = new node();
    int value = head1->val + head2->val + *carry;
    new_node->val = value%10;
    new_node->next = temp1;
    *carry = value >= 10 ? 1 : 0;
    return new_node;
}
int count_node(node *head)
{
    node* temp = head;
    int count_t = 0;
    while(temp!=NULL)
    {
        count_t++;
        temp = temp->next;
    }
    return count_t;
}
void pad_zeroes(node** head, int n)
{
    while(n)
    {
        node* new_node = new node();
        new_node->val = 0;
        new_node->next = *head;
        *head = new_node;
        n--;
    }
}
int main()
{
    Linked_list l1;
    Linked_list l2;
    l1.Add_node(6);
    l1.Add_node(1);
    l1.Add_node(7);
    l1.Add_node(3);
    l1.print_linked_list();
    l2.Add_node(9);
    l2.Add_node(9);
    l2.Add_node(9);
    l2.Add_node(2);
    l2.Add_node(9);
    l2.Add_node(5);
    l2.print_linked_list();
    int count1 = count_node(l1.head);
    int count2 = count_node(l2.head);
    if(count1 > count2)
        pad_zeroes(&l2.head, count1-count2);
    else if(count2 > count1)
        pad_zeroes(&l1.head, count2-count1);
    cout<<endl<<endl;
    l1.print_linked_list();
    l2.print_linked_list();
    int carry = 0;
    Linked_list l3;
    cout<<endl<<endl;
    l3.head = add_linked_list_number(l1.head,l2.head,&carry);
    if(carry > 0)
    {
        node* new_node = new node();
        new_node->val = carry;
        new_node->next = l3.head;
        l3.head = new_node;
    }
    l3.print_linked_list();
    return 0;
}
