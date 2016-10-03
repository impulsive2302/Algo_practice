
#include <iostream>
using namespace std;
struct node {
    int val;
    node* right;
    node* left;
};
void printInorder(node* root)
{
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->val<<"    ";
    printInorder(root->right);
}
struct node* newNode(int data)
{
     struct node* node1 = new node();
     node1->val = data;
     node1->left = NULL;
     node1->right = NULL;

     return node1;
}
void toSumTree(node* root)
{
    if(root == NULL)
        return 0;
    int old = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return root->data + old;
}
int main()
{
    struct node *root = NULL;
  int x;

  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);

  toSumTree(root);

  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);

  getchar();
  return 0;
}
