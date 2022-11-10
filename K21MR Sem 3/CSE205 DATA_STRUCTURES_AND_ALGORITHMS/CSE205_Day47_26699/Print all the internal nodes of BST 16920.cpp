#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
node *loc = NULL, *locp = NULL;
void find(int key)
{
    node *ptr = root, *par = NULL;
    while (ptr != NULL)
    {
        if (key < ptr->data)
        {
            par = ptr;
            ptr = ptr->left;
        }
        else if (key > ptr->data)
        {
            par = ptr;
            ptr = ptr->right;
        }
        else
        {
            loc = ptr;
            break;
        }
    }
    loc = ptr;
    locp = par;
}
void insertInBst(int data)
{
    find(data);
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (locp == NULL)
        root = newnode;
    else if (data > locp->data)
    {
        locp->right = newnode;
    }
    else if (data < locp->data)
    {
        locp->left = newnode;
    }
}
void displayInternal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        displayInternal(root->left);
        if (root->left != NULL || root->right != NULL)
            cout << root->data << " ";
        displayInternal(root->right);
    }
}
int main()
{
    int totalNodes, data;
    cin >> totalNodes;
    for (int i = 0; i < totalNodes; i++)
    {
        cin >> data;
        insertInBst(data);
    }
    displayInternal(root);
    return 0;
}