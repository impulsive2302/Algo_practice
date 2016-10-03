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
void check_sum(int a[],int len,int sum)
{
    int temp = 0;
    for(int i = 0;i<len;i++)
      {
          temp+=a[i];
          cout<<a[i]<<" ";
      }
    if(sum == temp)
        cout<<endl<<"Deepak found the sum with "<<sum;
    cout<<endl;
}
void find_sum_from_root_to_leaf(node* root,int path[],int pathlen,int sum)
{
    if(root == NULL)
        return;
    path[pathlen++] = root->val;
    if(root->left == NULL && root->right == NULL)
        check_sum(path,pathlen,sum);
    else
    {
        find_sum_from_root_to_leaf(root->left, path, pathlen,sum);
        find_sum_from_root_to_leaf(root->right, path, pathlen,sum);
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
  int len = 0;
  int arr[1000] = {0};
  find_sum_from_root_to_leaf(root,arr,len,21);
  return 0;
}
