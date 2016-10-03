#include <iostream>
using namespace std;
struct node {
    int val;
    node* right;
    node* left;
};
void Inorder(node* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    cout<<root->val<<"    ";
    Inorder(root->right);
}
struct node* newNode(int data)
{
     struct node* node1 = new node();
     node1->val = data;
     node1->left = NULL;
     node1->right = NULL;

     return node1;
}
void Moris_Inorder_traversal(node* root)
{
    if(root == NULL)
        return;
    node* pre= NULL;node *current = NULL;
    current = root;
    while(current!= NULL)
    {
        if(current->right == NULL)
        {
            cout<<current->val<<"   ";
            current = current->left;
        } else {
            //Find the inorder predecessor of current
            pre = current->right;
            while(pre->left !=NULL && pre->left != current)
                pre = pre->left;
            if(pre->left == NULL)
            {
                pre->left = current;
                current = current->right;
            } else {
                pre->left = NULL;
                cout<<current->val<<"   ";
                current = current->left;
            }
        }
    }
}
int main()
{
    struct node *root  = newNode(6);
     root->left             = newNode(4);
     root->right           = newNode(8);
     root->right->left           = newNode(7);
     root->right->right           = newNode(14);
     root->left->left     = newNode(2);
     root->left->right   = newNode(5);
      Moris_Inorder_traversal(root);
      cout<<endl;
     Inorder(root);
}

