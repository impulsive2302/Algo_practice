
#include <iostream>
#include <vector>
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
bool findPath(node* root, int k, vector <int> &path)
{
    if(root ==NULL)
        return false;
    path.push_back(root->val);
    if (root->val == k)
        return true;
    if((root->left &&findPath(root->left,k,path)) ||
       (root->right &&findPath(root->right,k,path)))
        return true;
    path.pop_back();
    return false;
}
int  findLCA(node* root, int n1, int n2)
{
    int i;
    vector <int> path1, path2;
     if ( !findPath(root, n1, path1) || !findPath(root, n2, path2))
          return -1;
     for(i = 0;i<path1.size() && i<path2.size();i++)
        if (path1[i] != path2[i])
            break;
     return path1[i-1];
}
int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
