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
bool isCompleteBT(node* root)
{
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->left!=NULL && root->right == NULL)
    {
        if(root->left->left == NULL && root->left->right == NULL)
            return true;
        else return false;
    }
    if(root->right!=NULL && root->left == NULL)
    {
        if(root->right->left == NULL && root->right->right == NULL)
            return true;
        else return false;
    }
    return (isCompleteBT(root->left) && isCompleteBT(root->right));
}
int main()
{
     /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);
  root->right->right->right = newNode(6);

  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");

  return 0;
}
