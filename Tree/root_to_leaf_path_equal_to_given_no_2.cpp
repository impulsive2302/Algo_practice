#include <iostream>
using namespace std;
int size= 0;
struct node{
    int val;
    node* left;
    node* right;
};
void print_inorder(node* root)
{
    if(root != NULL){
            size++;
    print_inorder(root->left);
    cout<<root->val<<"  ";
    print_inorder(root->right);
    }
    else return;
}
struct node* newnode(int dataa)
{
    node *temp = new node();
    temp->val = dataa;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
bool find_sum_from_root_to_leaf(node* root,int sum)
{
    if(root == NULL)
        return (sum==0);
    int subsum = sum-root->val;
    int ans = 0;
    if(subsum == 0 && root->left == NULL && root->right ==NULL)
        return 1;
    else
    {
        ans = ans || find_sum_from_root_to_leaf(root->left,subsum);
        ans = ans || find_sum_from_root_to_leaf(root->right,subsum);
    }
}
int main()
{
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  if(find_sum_from_root_to_leaf(root,21))
    cout<<"Found";
  else
    cout<<"not found";
  return 0;
}
