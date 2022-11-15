#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    struct node *left, *right;
};

node *newNode(int data)
{
    node *temp = new node;

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node *constructTreeUtil(int post[], int *postIndex, int key, int min, int max, int size)
{
    if (postIndex < 0)
        return 0;

    node *root = NULL;
    if (key > min && key < max)
    {
        root = newNode(key);
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0)
        {

            root->right = constructTreeUtil(post, postIndex, post[*postIndex], key, max, size);

            root->left = constructTreeUtil(post, postIndex, post[*postIndex], min, key, size);
        }
    }
    return root;
}

node *constructTree(int post[], int size)
{
    int postIndex = size - 1;
    return constructTreeUtil(post, &postIndex, post[postIndex], INT_MIN, INT_MAX, size);
}

void printLeafNodes(node *root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
        printLeafNodes(root->left);

    if (root->right)
        printLeafNodes(root->right);
}

int main()
{
    int size;
    cin >> size;
    int post[size];
    for (int i = 0; i < size; i++)
        cin >> post[i];

    struct node *root = constructTree(post, size);
    printLeafNodes(root);
    return 0;
}