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
int width_at_level(node* root, int level)
{
    if(root == NULL)
        return 0;
    if(level == 1)
        return 1;
    return width_at_level(root->left,level-1) + width_at_level(root->right,level-1);
}
int get_height(node* root)
{
    if(root == NULL)
        return 0;
    int lheight = get_height(root->left);
    int rheight = get_height(root->right);
    return ((lheight > rheight)?lheight:rheight + 1);
}
int getMaxWidth(node* root)
{
    int height = get_height(root);
    int max_width = 0;
    for(int i = 1;i< height;i++)
    {
        int temp_h = width_at_level(root,i);
        if(max_width< temp_h)  max_width = temp_h;
    }
    return max_width;
}
int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);
  root->right->right->left  = newNode(6);
  root->right->right->right  = newNode(7);

  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8
              /  \
             6   7
  */
  printf("Maximum width is %d \n", getMaxWidth(root));
  return 0;
}
