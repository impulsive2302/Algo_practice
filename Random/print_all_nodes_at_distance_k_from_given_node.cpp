#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printdistanceNodeDown(node* target, int k)
{
    if (target==NULL || k<0) return ;
    if (k==0) {
        cout<<target->data<<endl;
        return;
    }
    printdistanceNodeDown(target->left,k-1);
    printdistanceNodeDown(target->right,k-1);
}

int printkdistanceNode(node* root, node* target, int k)
{
    if(!root)
        return -1;
    if (root == target)
    {
        printdistanceNodeDown(root,k);
        return 0;
    }

    int dl = printkdistanceNode(root->left,target,k);
    if (dl!=-1)
    {
        if (dl+1==k)
            cout<<root->data<<endl;
        else
            printdistanceNodeDown(root->right,k-dl-2);
        return dl+1;
    }
    int dr = printkdistanceNode(root->right,target,k);
    if (dr!=-1)
    {
        if (dr+1==k)
            cout<<root->data<<endl;
        else
            printdistanceNodeDown(root->left,k-dr-2);
        return dr+1;
    }
    return -1;
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
