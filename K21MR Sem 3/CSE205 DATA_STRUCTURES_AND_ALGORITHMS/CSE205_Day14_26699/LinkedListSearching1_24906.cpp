#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void push(int n)
{
    Node *ptr;
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
void print()
{
    int min = INT_MAX;
    Node *n = head;
    while (n != NULL)
    {
        if(min > n->data){
            min = n->data;
        }
        n = n->next;
    }
    cout<<min;
}
int main()
{
    int n = 5;
    int data;
    while (n--)
    {
        cin >> data;
        push(data);
    }
    print();
    return 0;
}