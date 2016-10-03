#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
};
class Linked_list {
public:
    node* head;
    Linked_list(){
        head = NULL;
    }
    void Add_node(int val) {
        node* temp = head;
        node* n = new node();
        n->val = val;
        n->next = NULL;
        if(head) {
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = n;
        } else {
            head = n;
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
