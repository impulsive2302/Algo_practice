
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
bool is_balanced(node* root, int* height)
{
    int lh = 0,rh = 0;
    int l = 0,r = 0;
    if(root == NULL)
    {
        *height = 0;
        return true;
    }
    l = is_balanced(root->left,&lh);
    r = is_balanced(root->right,&rh);

    *height = 1+ (lh>rh?lh:rh);
    if((lh-rh)>=2 || (rh-lh)>=2)
        return false;

    else return l&&r;

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
      root->left->left->left->left = newNode(9);
      int height = 0;
      if(is_balanced(root,&height))
        cout<<"The tree is balanced";
      else
        cout<<"The tree is not balanced";
     //Inorder(root);
}
