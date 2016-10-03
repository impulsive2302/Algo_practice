#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
    node* previous;
};
class double_linked_list{
public:
    double_linked_list(){
        head = NULL;
    }
    node* head;
    void insert_node(int val)
    {
        node* new_node = new node();
        new_node->val = val;
        new_node->next = NULL;
        new_node->previous = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            node *temp = head;
            while(temp->next !=NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->previous = temp;
        }
    }
    void print_linked_list() {
        node *temp = head;
        while(temp){
            cout<<temp->val<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }

};
