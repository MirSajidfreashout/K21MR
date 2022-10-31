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

Node *kthSmallest(Node *root, int *counter, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *left = kthSmallest(root->left, counter, k);
    if (left != NULL)
        return left;
    if (++(*counter) == k)
        return root;
    return kthSmallest(root->right, counter, k);
}
Node *findKthSmallest(Node *root, int k)
{
    int counter = 0;
    return kthSmallest(root, &counter, k);
}

int main()
{
    Node *root = NULL;
    int t;
    cin >> t;
    if (t <= 2 || t > 10)
    {
        cout << "Invalid Size";
        exit(0);
    }
    else
    {
        while (t--)
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
    }
    Node *result = findKthSmallest(root, 2);
    cout << result->data;
    return 0;
}