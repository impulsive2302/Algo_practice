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
bool IsFoldable_util(node* left,node* right)
{
    if(left == NULL && right == NULL)
        return true;
    if(left == NULL || right == NULL)
        return false;
    return (IsFoldable_util(left->left,right->right) && IsFoldable_util(left->right,right->left));
}
bool IsFoldable(node* root)
{
    if(root == NULL)
        return true;
    return IsFoldable_util(root->left,root->right);
}
int main()
{/* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);

  if(IsFoldable(root) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }

  getchar();
  return 0;
}

