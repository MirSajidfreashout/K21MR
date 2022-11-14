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

int minHeight(Node *root)
{
    int l = INT_MAX, r = INT_MAX;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left)
        l = minHeight(root->left);
    if (root->right)
        r = minHeight(root->right);
    return min(l, r) + 1;
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
    cout << minHeight(root) - 1;
    return 0;
}