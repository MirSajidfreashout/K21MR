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

void printLeaf(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
    if (root->right)
        printLeaf(root->right);
    if (root->left)
        printLeaf(root->left);
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
    printLeaf(root);
}