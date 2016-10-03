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
int n_largest_element(node* root, int n)
{
    static int a= 0;
    if(root ==NULL)
        return 0;
    int val = 0;
    val= (val+ n_largest_element(root->left,n));
        a = a+1;
        if(n == a)
            return root->val;
    val = (val+ n_largest_element(root->right,n));
    return val;
}
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  cout<<"Nth largest element in tree is "<<n_largest_element(root,5);
  printf("\n\n\n\n");
  Inorder(root);
}

