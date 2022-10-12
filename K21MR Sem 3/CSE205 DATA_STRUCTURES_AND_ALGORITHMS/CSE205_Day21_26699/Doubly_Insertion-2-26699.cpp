#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;

void pushTail(int data)
{
    Node *newNode = new Node;
    Node *tail = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        pushTail(x);
    }
    display();
    return 0;
}