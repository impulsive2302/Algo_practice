#include <iostream>
#include "Linked_list.h"

node* merge_list(node* a, node* b){
    node * res = NULL;
    while(a!=NULL && b!=NULL) {
        if(a->val < b->val) {
            node* tmp = a->next;
            a->next = res;
            res = a;
            a = tmp;
        } else {
            node * tmp = b->next;
            b->next = res;
            res = b;
            b = tmp;
        }
    }
    while(a!=NULL) {
        node* tmp = a->next;
        a->next = res;
        res = a;
        a = tmp;
    }
    while(b!=NULL) {
        node * tmp = b->next;
        b->next = res;
        res = b;
        b = tmp;
    }
    return res;
}
int main() {
    Linked_list l1;
    Linked_list l2;
    l1.Add_node(5);
    l1.Add_node(10);
    l1.Add_node(15);
    l1.print_linked_list();
    l2.Add_node(2);
    l2.Add_node(3);
    l2.Add_node(20);
    l2.Add_node(30);
    l2.print_linked_list();
    node * Final_HEAD = merge_list(l1.head,l2.head);
    while(Final_HEAD->next!=NULL){
        cout << Final_HEAD->val<<"      ";
        Final_HEAD = Final_HEAD->next;
    }
    return 0;
}
