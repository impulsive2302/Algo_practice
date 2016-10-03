#include <iostream>
#include<stdint.h>
using namespace std;
struct node
{
    int data;
    struct node* npx;
};
class XOR_Linked_list {
    node* head;
    public:
    XOR_Linked_list() {
        head = NULL;
    }
    struct node* XOR(struct node *a, struct node *b)
    {
        return (struct node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
    }
    void insert(int data)
    {
        // Allocate memory for new node
        struct node *new_node  = new node();
        new_node->data = data;

        /* Since new node is being inserted at the begining, npx of new node
           will always be XOR of current head and NULL */
        new_node->npx = XOR(head, NULL);

        /* If linked list is not empty, then npx of current head node will be XOR
           of new node and node next to current head */
        if (head != NULL)
        {
            // *(head_ref)->npx is XOR of NULL and next. So if we do XOR of
            // it with NULL, we get next
            struct node* next = XOR(head->npx,  NULL);
            head->npx = XOR(new_node, next);
        }

        // Change head
        head = new_node;
    }
    // prints contents of doubly linked list in forward direction
    void printList ()
    {
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *next;

        printf ("Following are the nodes of Linked List: \n");

        while (curr != NULL)
        {
            // print current node
            printf ("%d ", curr->data);

            // get address of next node: curr->npx is next^prev, so curr->npx^prev
            // will be next^prev^prev which is next
            next = XOR (prev, curr->npx);

            // update prev and curr for next iteration
            prev = curr;
            curr = next;
        }
    }
};
int main()
{
    XOR_Linked_list xll;
    xll.insert(5);
    xll.insert(4);
    xll.insert(3);
    xll.insert(2);
    xll.insert(1);
    xll.printList();
}
