
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
convert_children_sum_property(node* root)
{
    if(root==NULL)
        return 0;
    int lc = 0;
    int rc = 0;
    lc += convert_children_sum_property(root->left);
    rc += convert_children_sum_property(root->right);
    if((lc+rc)! = 0)
    {

    }
    return root->val;
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
