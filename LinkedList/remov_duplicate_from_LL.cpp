#include"Linked_List.h"
using namespace  std;
void remove_duplicate(node* head)
{
    node* temp = head;
    node* delete_node;
    while(temp->next!=NULL)
    {
        if(temp->val == temp->next->val)
        {
            delete_node = temp->next;
            temp->next = temp->next->next;
            delete(delete_node);
        } else {
            temp = temp->next;
        }
    }
}
int main()
{
    Linked_list l;
    l.Add_node(11);
    l.Add_node(11);
    l.Add_node(11);
    l.Add_node(23);
    l.Add_node(45);
    l.Add_node(45);
    l.Add_node(60);
    l.print_linked_list();
    remove_duplicate(l.head);
    l.print_linked_list();
}
