
#include <iostream>
using namespace std;
int size= 0;
struct node{
    char val;
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
int search_in_in(char pre[], int start, int last, int val)
{
    for(int i = start;i<=last;i++)
    {
        if(pre[i] == val)
        {
            return i;
            break;
        }
    }
}
struct node* buildTree(char in[], char pre[], int start, int last)
{
    if(start>last)
        return NULL;
    static int preIndex = 0;
    node* temp = newnode(pre[preIndex++]);
    if(start == last)
        return temp;
    int index_in_pre = search_in_in(in,start, last,temp->val);
    temp->left = buildTree(in,pre,start,index_in_pre-1);
    temp->right = buildTree(in,pre,index_in_pre+1,last);
    return temp;
}
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  print_inorder(root);
  return 0;
}
