
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
node* constructTreeUtil(int pre[],char preLN[],int arr_size,int *preIndex)
{
    int index = *preIndex;
    if(index == arr_size)
        return NULL;
    node* root = newNode(pre[index]);
    (*preIndex)++;

    if(preLN[index] == 'N')
    {
        root->left = constructTreeUtil(pre,preLN,arr_size,preIndex);
        root->right = constructTreeUtil(pre,preLN,arr_size,preIndex);
    }
    return root;
}
node* constructTree(int pre[],char preLN[],int arr_size)
{
    int index = 0;
    return constructTreeUtil(pre,preLN,arr_size,&index);
}
int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    // construct the above tree
    root = constructTree (pre, preLN, n);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);

    return 0;
}
