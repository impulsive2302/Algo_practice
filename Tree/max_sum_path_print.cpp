#include <iostream>
#include<limits.h>
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
bool PrintPath(node* root, node* ref_node)
{
    if(root == NULL)
        return false;
    if(root == ref_node || PrintPath(root->left, ref_node) || PrintPath(root->right, ref_node))
    {
        cout <<root->val<<" ";
        return true;
    }
    return false;
}
void maxSumPathUtil(node* root, int *sum, int curr_sum,node** ref_node)
{
    if(root == NULL)
        return;
    curr_sum += root->val;
    if(curr_sum > *sum)
    {
        *sum = curr_sum;
        *ref_node = root;
    }
    maxSumPathUtil(root->left,sum,curr_sum,ref_node);
    maxSumPathUtil(root->right,sum,curr_sum,ref_node);
}
int maxSumPath(node* root)
{
    if(root == NULL)
        return 0;
    int sum = INT_MIN;
    node* ref_node = NULL;
    maxSumPathUtil(root,&sum,0,&ref_node);
    PrintPath(root, ref_node);
    return sum;
}
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);
    return 0;
}

