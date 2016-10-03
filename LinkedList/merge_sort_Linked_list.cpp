#include "Linked_List.h"
using namespace  std;
void print_list(node* head)
{
    node* temp = head;
    cout<<"Calling Print Function"<<endl;
     while(temp){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }
        cout<<endl;
}
void split_Linked_list_eqaual_halves(node* head, node **front, node **back)
{
        if(head == NULL || head->next == NULL)
        {
            *front = head;
            *back = NULL;
        }
        node* slow = head;
        node* fast = head->next;
        while(fast!=NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front = head;
        *back = slow->next;
        slow->next = NULL;
}
node* Merge_linked_list(node* a, node*b)
{
    node* result = NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->val<=b->val)
    {
        result = a;
        result->next = Merge_linked_list(a->next,b);
    }
    else
    {
        result = b;
        result->next = Merge_linked_list(a,b->next);
    }

    return result;
}
void merge_sort_linked_list(node** headref)
{
    node* head = *headref;
    if(head == NULL || head->next ==NULL)
        return;
    node *a, *b;
    split_Linked_list_eqaual_halves(head,&a, &b);
    //print_list(a);
    //print_list(b);
    merge_sort_linked_list(&a);
    merge_sort_linked_list(&b);
    *headref = Merge_linked_list(a,b);
}
int main()
{
    Linked_list l1;
    l1.Add_node(3);
    l1.Add_node(2);
    l1.Add_node(9);
    l1.Add_node(4);
    l1.Add_node(8);
    l1.Add_node(12);
    l1.Add_node(18);
    l1.Add_node(11);
    cout<<"Original Linked List\n";
    l1.print_linked_list();
    merge_sort_linked_list(&l1.head);
    cout<<"Sorted List\n";
    l1.print_linked_list();
}
