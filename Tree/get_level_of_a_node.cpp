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
void getLevelUtil(node* root,int x, int level, int* out)
{
    if(root == NULL)
        return;
    if(root->val == x)
        *out = level;
    getLevelUtil(root->left,x,level+1,out);
    getLevelUtil(root->right,x,level+1,out);
}
int getLevel(node* root, int x)
{
    if(root == NULL)
        return -1;
    int level;
    getLevelUtil(root,x,1,&level);
    return level;
}

int main()
{
    struct node *root = new struct node;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++)
    {
      int level = getLevel(root, x);
      if (level)
        printf(" Level of %d is %d\n", x, getLevel(root, x));
      else
        printf(" %d is not present in tree \n", x);

    }
    return 0;
}

