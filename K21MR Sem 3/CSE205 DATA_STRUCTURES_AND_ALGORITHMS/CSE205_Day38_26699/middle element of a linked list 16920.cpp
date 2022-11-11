#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};
Node *head = NULL;
void push(char x)
{
    Node *newNode = new Node;
    newNode->data = x;
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
}

void middleElement()
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (count % 2 == 1)
    {
        count /= 2;
        Node *temp2 = head;
        while (count--)
        {
            temp2 = temp2->next;
        }
        cout << temp2->data;
    }
    else
    {
        count /= 2;
        count--;
        Node *temp2 = head;
        while (count--)
        {
            temp2 = temp2->next;
        }
        cout << temp2->data;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char x;
        cin >> x;
        push(x);
    }
    middleElement();
}