#include "Linked_List.h"
#include<iostream>
#include<map>

using namespace std;

void remove_dup(node* head)
{
    if(!head)
        return;
    node* temp = head;
    map<int,int> m;
    m[temp->val] = temp->val;
    while(temp!=NULL && temp->next != NULL)
    {
        if(m.find(temp->next->val) != m.end())
        {
            temp->next = temp->next->next;
        } else {
            m[temp->next->val] = temp->next->val;
            temp = temp->next;
        }
    }
}
int main(){
    Linked_list l1;
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.Add_node(3);
    l1.Add_node(5);
    l1.Add_node(1);
    l1.Add_node(6);
    l1.Add_node(7);
    l1.Add_node(3);
    l1.Add_node(2);
    remove_dup(l1.head);
    l1.print_linked_list();
}

