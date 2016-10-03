#include"Linked_List.h"
using namespace  std;
node* Segregate_even_odd(node* head)
{
    node* even = NULL;
    node* odd = NULL;
    node* odd_head = NULL;
    node* temp_itr = head->next;
    node* prev = head;
    if((head->val%2) == 0)
    {
           even = head;
    }
    else
    {
           odd = head;
           odd_head = head;
    }

    while(temp_itr!=NULL)
    {
        if((temp_itr->val % 2) == 0)
        {
            //Handle even Nodes
            if(even == NULL)
            {
                head = temp_itr;
            }
            if(odd != NULL)
            {
                if(even == NULL)
                    even = temp_itr;
                else
                    even->next = temp_itr;
                prev->next = temp_itr->next;
                temp_itr->next = odd_head;
            }
            even = temp_itr;
        }
        else
        {
            //Handle odd Nodes
            if(odd == NULL)
                odd_head = temp_itr;
            odd = temp_itr;
        }
        prev = temp_itr;
        temp_itr = temp_itr->next;
    }
    return head;
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
    cout<<"Original Linked list\n";
    l1.print_linked_list();
    l1.head = Segregate_even_odd(l1.head);
    cout<<"After Segregation\n";
    l1.print_linked_list();
}
