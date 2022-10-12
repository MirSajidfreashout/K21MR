#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node *prev;
};
Node *head = NULL; // global head pointer
Node *last = NULL; // global last pointer

void pushTail(string data)
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
void pushHead(string data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}
void displayRev()
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp!=head->prev)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}

int main()
{
    string name;
    for (int i = 0; i < 5; i++)
    {
        cin >> name;
        pushTail(name);
    }
    cin >> name;
    pushHead(name);
    displayRev();
    return 0;
}