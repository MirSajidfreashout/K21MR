#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *create()
{
    int ch;
    cin >> ch;
    if (ch == -1)
        return NULL;
    else
    {
        Node *newNode = new Node;
        newNode->data = ch;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->left = create();
        newNode->right = create();
        return newNode;
    }
}
void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PreOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(Node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    root = create();
    cout << "InOrder Traversal: ";
    InOrder(root);
    cout << "\nPreOrder Traversal: ";
    PreOrder(root);
    cout << "\nPostOrder Traversal: ";
    PostOrder(root);
    return 0;
}