
#include"Linked_List.h"
using namespace  std;
node* reverse_ll_Alternate_in_group(node* head, int group)
{
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count =0;
    while(current!=NULL && count < group)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current  = next;
        count++;
    }
    if(head != NULL)
      head->next = current;
    count = 0;
    while(count < group-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
    if(current!=NULL)
        current->next = reverse_ll_Alternate_in_group(current->next,group);

    return prev;
}
int main()
{
    Linked_list l1;
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.Add_node(4);
    l1.Add_node(5);
    l1.Add_node(6);
    l1.Add_node(7);
    l1.Add_node(8);
    l1.Add_node(9);
    l1.Add_node(10);
    l1.Add_node(11);
    l1.print_linked_list();
    l1.head = reverse_ll_Alternate_in_group(l1.head,3);
    l1.print_linked_list();
}
