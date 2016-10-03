#include <iostream>
#include <math.h>
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
int height(node* root)
{
    if(root == NULL)
        return 0;
    return 1+ max(height(root->left),height(root->right));
}
int diameter(node* root)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int main()
{
    struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->left->left     = newNode(4);
     root->left->left->left->left    = newNode(4);
     root->left->left->left->left->left     = newNode(4);
     root->left->right   = newNode(5);

     cout<<"Diameter of the tree is "<<diameter(root);;
}

