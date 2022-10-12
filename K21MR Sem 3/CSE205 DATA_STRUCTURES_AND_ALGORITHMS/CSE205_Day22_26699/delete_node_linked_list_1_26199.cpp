#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int val)
    {
        data = val;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    int size = 0;
    LinkedList(int val)
    {
        head = new Node(val);
        size++;
    }

    LinkedList(){};

    // Insert element in list
    void push(int val)
    {
        size++;
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }

        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(val);
    }

    void deleteNode(int index)
    {
        if (head == nullptr)
            return;
        else if (index == 0)
        {
            head = head->next;
            size--;
            return;
        }

        Node *ptr = head;
        int i = 1;
        for (; ptr->next != nullptr && i < index; i++)
            ptr = ptr->next;
        if (i == index)
        {
            ptr->next = ptr->next->next;
            size--;
        }
    };
};

int main()
{
    int n;
    cin >> n;
    LinkedList ll;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        ll.push(elem);
    }
    int index;
    cin >> index;
    if (index < 0 || index >= n)
    {
        cout << "Invalid Position";
        return 0;
    }
    ll.deleteNode(index);
    if (ll.head != nullptr)
        for (auto ptr = ll.head; ptr != NULL; ptr = ptr->next)
            cout << ptr->data << ' ';
    else
        cout << "SLL is Empty";
    return 0;
}