int height(Node *root)
{
    int leftHeight = -1, rightHeight = -1;
    if (root->left)
    {
        leftHeight = height(root->left);
    }
    if (root->right)
        rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}