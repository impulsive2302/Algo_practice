#include"Linked_List.h"
using namespace  std;
node* intersection_of_two_LL(node* head1,node* head2)
{
    Linked_list Temp;
    if(!head1 &&!head2)
        return NULL;
    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val == temp2->val) {
            Temp.Add_node(temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if(temp1->val <temp2->val) {
            temp1 = temp1->next;
        } else {
            temp2 = temp2->next;
        }
    }
    return Temp.head;
}

int main()
{
    Linked_list l1;
    Linked_list l2;
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.Add_node(4);
    l1.Add_node(5);
    l1.Add_node(6);
    l1.print_linked_list();
    l2.Add_node(2);
    l2.Add_node(4);
    l2.Add_node(6);
    l2.Add_node(8);
    l2.print_linked_list();
    Linked_list l3;
    l3.head = intersection_of_two_LL(l1.head,l2.head);
    l3.print_linked_list();
    return 0;

}
