#include<iostream>
#include"Linked_List.h"
#include<stack>
using namespace std;
bool is_palin(node* head)
{
    stack<int> st;
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast!=NULL)
        slow = slow->next;
    while(slow!=NULL)
    {
        int val1 = st.top();
        //cout<<val1<<endl;
        st.pop();
        if(val1!=slow->val)
            return false;
        slow = slow->next;
    }
    return true;
}
int main()
{
    Linked_list l1;
    l1.Add_node(9);
    l1.Add_node(1);
    l1.Add_node(2);
    l1.Add_node(1);
    l1.Add_node(0);
    l1.print_linked_list();
    if(is_palin(l1.head))
        cout<<"LL is a Palindrome\n";
    else
        cout<<"LL is not a Palindrome\n";
    return 0;
}

