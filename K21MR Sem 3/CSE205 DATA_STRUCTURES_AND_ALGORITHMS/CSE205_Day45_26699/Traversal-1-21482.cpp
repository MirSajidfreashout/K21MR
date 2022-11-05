#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return newNode(data);
        else
        {
            if (data <= root->data)
                root->left = insert(root->left, data);
            else
                root->right = insert(root->right, data);
            return root;
        }
}
void postOrder(Node *root)
{
    if(root == NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    postOrder(root);
    return 0;
}