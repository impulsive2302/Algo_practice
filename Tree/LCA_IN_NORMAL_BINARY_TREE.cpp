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
node* findLCA(node* root, int n1, int n2)
{
    node* Lrca;
    node* Rrca;
    if(root == NULL)
        return NULL;
    if(root->val == n1 || root->val == n2)
        return root;
    Lrca = findLCA(root->left,n1,n2);
    Rrca = findLCA(root->right,n1,n2);

    if(Lrca != NULL && Rrca !=NULL)
        return root;
    return (Lrca!=NULL)? Lrca :Rrca;
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
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->val;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->val;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->val;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->val;
}
