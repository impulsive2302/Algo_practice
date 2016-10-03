
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
void increment(node* node, int diff)
{
    if(node->left!=NULL)
    {
        node->left->val = node->left->val + diff;
        increment(node->left,diff);
    }
    else if(node->right!=NULL)
    {
        node->right->val = node->right->val+diff;
        increment(node->right,diff);
    }
}
void convert_children_sum_property(node* root)
{
    int lc = 0; int rc =0;int diff;
    if(root == NULL ||(root->left == NULL && root->right == NULL))
        return;
    convert_children_sum_property(root->left);
    convert_children_sum_property(root->right);
    if(root->left!=NULL)
        lc = root->left->val;
    if(root->right!=NULL)
        rc = root->right->val;
    diff = lc + rc - root->val;
    if(diff > 0)
    {
        root->val = root->val + diff;
    }
    if(diff < 0)
    {
        increment(root, -diff);
    }
}
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
  cout<<"Before conversion\n";;
  Inorder(root);
  convert_children_sum_property(root);
  cout<<"\nAfter conversion\n";;
  Inorder(root);
}
