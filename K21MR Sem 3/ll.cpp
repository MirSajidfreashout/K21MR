#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
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

void printReverse(int count)
{
    Node *temp = head;
    for (int i = count; i > 1; i--)
    {
        for (int j = 0; j < count - 1; j++)
        {
            temp = temp->next;
            cout << temp->data;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int size = n;
    while (n--)
    {
        int x;
        cin >> x;
        insert(x);
    }
    // printList();
    // cout << endl;
    printReverse(size);
    return 0;
}