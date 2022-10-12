#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    int strength;
    Node *next;
};

Node *head = NULL;

void pushBack()
{
    Node *newNode = new Node;
    cin >> newNode->name;
    cin >> newNode->strength;
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

void sort_ll()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        Node *p = ptr->next;
        while (p != NULL)
        {
            if (ptr->strength < p->strength)
            {
                string s = ptr->name;
                ptr->name = p->name;
                p->name = s;
                int temp = ptr->strength;
                ptr->strength = p->strength;
                p->strength = temp;
            }
            p = p->next;
        }
        ptr = ptr->next;
    }
}

void printList()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->name << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    if (n >= 5 && n <= 10)
    {
        while (n--)
        {
            pushBack();
        }
        sort_ll();
        printList();
        pushBack();
        sort_ll();
        printList();
    }
    else
    {
        cout << "Invalid Input";
    }
    return 0;
}