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
        if(current->left == NULL)
        {
            cout<<current->val<<"   ";
            current = current->right;
        } else {
            //Find the inorder predecessor of current
            pre = current->left;
            while(pre->right !=NULL && pre->right != current)
                pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = NULL;
                cout<<current->val<<"   ";
                current = current->right;
            }
        }
    }
}
int main()
{
    struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);
      Moris_Inorder_traversal(root);
      cout<<endl;
     Inorder(root);
}

