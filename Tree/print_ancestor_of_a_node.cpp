#include <iostream>
#include<vector>
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
struct node* newnode(int data)
{
     struct node* node1 = new node();
     node1->val = data;
     node1->left = NULL;
     node1->right = NULL;

     return node1;
}
void print_ancestor(int a[],int len)
{
    for(int i = len-2;i>=0;i--)
        cout<<a[i]<<"   ";
    cout<<endl;

}
void printAncestorsUtil(node* root,int x, int path_arr[],int pathlen)
{
    if(root == NULL)
        return;
    path_arr[pathlen++] = root->val;
    if(root->val == x)
    {
        print_ancestor(path_arr,pathlen);
    }
    printAncestorsUtil(root->left,x,path_arr,pathlen);
    printAncestorsUtil(root->right,x,path_arr,pathlen);
}
void printAncestors(node* root, int x)
{
    int path_arr[500];
    printAncestorsUtil(root,x,path_arr,0);
}
int main()
{
    /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  printAncestors(root, 7);

  getchar();
  return 0;
}

