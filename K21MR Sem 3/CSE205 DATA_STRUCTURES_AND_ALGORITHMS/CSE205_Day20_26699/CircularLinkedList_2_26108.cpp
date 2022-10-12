#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void printList();

void pushBack()
{
    Node *newNode = new Node;
    cin >> newNode->data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    if (newNode->data % 2 == 0)
    {
        printList();
    }
}

void printList()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data % 2 == 0)
        {
            cout << ptr->data << " ";
        }
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int n = 6;
    while (n--)
    {
        pushBack();
    }
    return 0;
}