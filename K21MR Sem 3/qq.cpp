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
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// int search(Node *root, int key)
// {
//     if (root == NULL)
//         cout << "Empty";
//     if (root->data == key)
//         return root->data;
//     else if (root->data > key)
//         return search(root->left, key);
//     else
//         return search(root->right, key);
// }

Node* minNode(Node *root)
{
    if (root->left == NULL)
        return root;
    return minNode(root->left);
}

Node *deleteNode(Node *root, int item)
{
    if (root == NULL)
        return root;
    else if (item < root->data)
        root->left = deleteNode(root->left, item);
    else if (item > root->data)
        root->right = deleteNode(root->right, item);
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left == NULL)
        {
            Node* t = root->right;
            free(root);
            return t;
        }
        else if (root->right == NULL)
        {
            Node* t = root->left;
            free(root);
            return t;
        }
        Node* t = minNode(root->right);
        root->data = t->data;
        deleteNode(root->right, t->data);

    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 16);
    root = insert(root, 7);
    root = insert(root, 3);

    inorder(root);
    cout<<endl;
    deleteNode(root, 3);
    inorder(root);
    // cout << minNode(root);
    return 0;
}