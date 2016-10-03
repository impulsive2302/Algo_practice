#include <iostream>
#include<map>
using namespace std;
map <int,int> hash_map;
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
void vertical_sum_Util(node* root,int horizontal_distance)
{
    if(root == NULL)
        return;
    vertical_sum_Util(root->left,horizontal_distance-1);
    if(hash_map.count(horizontal_distance) == 0)
    {
        hash_map[horizontal_distance] = root->val;
    } else
    {
        hash_map[horizontal_distance] += root->val;
    }
    vertical_sum_Util(root->right,horizontal_distance+1);

}
void vertical_sum(node* root)
{
    if(root == NULL)
        return;

    vertical_sum_Util(root,0);
    for (map<int,int>::iterator it=hash_map.begin(); it!=hash_map.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
}
int main()
{
    struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);
     root->right->left     = newNode(6);
     root->right->right   = newNode(7);
     vertical_sum(root);
     //Inorder(root);
}

