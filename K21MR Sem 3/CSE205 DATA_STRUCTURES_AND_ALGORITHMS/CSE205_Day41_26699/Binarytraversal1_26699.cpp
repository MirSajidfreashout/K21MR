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
        return (newNode(data));
    else
    {
        if (data <= root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
}
int minDepth(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{
    Node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout<<minDepth(root)-1;
    return 0;
}