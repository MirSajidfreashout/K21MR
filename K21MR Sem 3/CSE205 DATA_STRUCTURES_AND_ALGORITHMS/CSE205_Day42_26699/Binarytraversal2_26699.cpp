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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if (leftDepth > rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
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
    int y;
    cin >> y;
    root = insert(root, y);
    cout << endl;
    cout << maxDepth(root) - 1;
    return 0;
}