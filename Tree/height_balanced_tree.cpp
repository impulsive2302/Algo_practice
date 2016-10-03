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
int height(node *root)
{
    if(root == NULL)
        return 0;
    return (1+max(height(root->left),height(root->right)));
}
bool is_balanced(node* root)
{
    if(root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1 &&
       is_balanced(root->left)&&
       is_balanced(root->right))
        return  1;
    return 0;
}
int main()
{
      struct node *root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);
      root->right->left = newNode(6);
      root->left->left->left = newNode(7);
     if(is_balanced(root))
        cout<<"The tree is balanced";
     else
        cout<<"The tree is not balanced";
}
