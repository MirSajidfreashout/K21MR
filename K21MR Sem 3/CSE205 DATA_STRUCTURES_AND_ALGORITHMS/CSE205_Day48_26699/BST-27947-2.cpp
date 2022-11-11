#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;
};

struct Node *newNode(int key)
{
    struct Node *ptr = new Node;
    ptr->key = key;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct Node *insert(struct Node *root, int key)
{
    if (!root)
        root = newNode(key);
    else if (root->key > key)
        root->left = insert(root->left, key);
    else if (root->key < key)
        root->right = insert(root->right, key);
    return root;
}

int distanceFromRoot(struct Node *root, int x)
{
    if (root->key == x)
        return 0;
    else if (root->key > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct Node *root, int a, int b)
{
    if (!root)
        return 0;
    else if (root->key > a && root->key > b)
        return distanceBetween2(root->left, a, b);
    else if (root->key < a && root->key < b) // same path
        return distanceBetween2(root->right, a, b);
    else
        return distanceFromRoot(root, a) +
               distanceFromRoot(root, b);
}

int findDistWrapper(Node *root, int a, int b)
{
    if (a > b)
        swap(a, b);
    return distanceBetween2(root, a, b);
}

int main()
{
    struct Node *root = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int a, b;
    cin >> a >> b;
    cout << findDistWrapper(root, a, b);
    return 0;
}
