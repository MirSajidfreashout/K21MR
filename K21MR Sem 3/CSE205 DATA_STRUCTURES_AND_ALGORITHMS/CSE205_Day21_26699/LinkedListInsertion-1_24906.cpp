#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtEnd(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtPos(int data, int pos)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }

        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "The prev node is null.";
        }
    }
}

void printList()
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
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        insertAtEnd(x);
    }
    int a, b;
    cin >> a >> b;
    insertAtPos(b, a);

    printList();

    return 0;
}