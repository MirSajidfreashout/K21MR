#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
Node* create()
{
    int ch; cin>>ch;
    if(ch == -1) return NULL;
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
int main()
{
    create();
    return 0;
}