#include <bits/stdc++.h>
using namespace std;

int binarySearch(int inorder[], int l, int r, int d)
{
    int mid = (l + r) >> 1;
    if (inorder[mid] == d)
        return mid;
    else if (inorder[mid] > d)
        return binarySearch(inorder, l, mid - 1, d);
    else
        return binarySearch(inorder, mid + 1, r, d);
}

void leafNodesRec(int preorder[], int inorder[], int l, int r, int *index, int n)
{
    if (l == r)
    {
        cout << inorder[l]<<" ";
        *index = *index + 1;
        return;
    }
    if (l < 0 || l > r || r >= n)
        return;
    int loc = binarySearch(inorder, l, r, preorder[*index]);
    *index = *index + 1;
    leafNodesRec(preorder, inorder, l, loc - 1, index, n);
    leafNodesRec(preorder, inorder, loc + 1, r, index, n);
}

void leafNodes(int preorder[], int n)
{
    int inorder[n];
    for (int i = 0; i < n; i++)
        inorder[i] = preorder[i];
    sort(inorder, inorder + n);
    int index = 0;
    leafNodesRec(preorder, inorder, 0, n - 1, &index, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    leafNodes(arr, n);
}