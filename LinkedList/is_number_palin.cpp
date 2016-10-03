#include"Linked_List.h"
using namespace  std;
bool is_palin(node **head, node* next)
{
    if(next ==NULL)
        return true;
    bool isp =  is_palin(head,next->next);
    if(!isp) return false;
    else
    {
        if((*head)->val !=next->val)
        {
            cout<<"head->val    next->val    returning false   "<<(*head)->val<<next->val<<endl;
            return false;//
        }
        else {
            cout<<"head->val    next->val    returning True    "<<(*head)->val<<next->val<<endl;
            *head = (*head)->next;
            //cout<< "Incrementing head = "<<(*head)->val<<endl;
            return true;
        }
    }
}
int main()
{
    Linked_list l1;
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.Add_node(2);
    l1.Add_node(3);
    l1.print_linked_list();
    if(is_palin(&l1.head,l1.head))
        cout<<"The number is Palindrome"<<endl;
    else
        cout<<"The number is not Palindrome"<<endl;
}
