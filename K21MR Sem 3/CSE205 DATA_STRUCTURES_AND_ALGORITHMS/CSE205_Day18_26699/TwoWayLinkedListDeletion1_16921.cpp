#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = NULL;
    Node *next = NULL;
    Node(int value, Node *prev = NULL, Node *next = NULL)
    {
        data = value;
        this->next = next;
        this->prev = prev;
    }
};

class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void pushFront(int data)
    {
        head = new Node(data, NULL, head);
        if (tail == nullptr)
            tail = head;
    }

    void pushBack(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            tail = head;
            return;
        }
        tail->next = new Node(data, tail, NULL);
        tail = tail->next;
    }
    bool count(int value)
    {
        int c = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == value)
            {
                c = c + 1;
            }
            ptr = ptr->next;
        }
        if (c < 2)
            return false;
        else
            return true;
    }
    void deletion(int value)
    {
        Node *ptr = tail;
        int c = 0;
        while (ptr != NULL)
        {
            if (ptr->data == value)
            {
                if (c == 0)
                {
                    c++;
                    ptr = ptr->prev;
                    continue;
                }
                if (ptr == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            ptr = ptr->prev;
        }
    }
    void display()
    {
        Node *ptr = tail;
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->prev;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    if (!(n > 2 && n <= 20))
    {
        cout << "Invalid list size";
        return 0;
    }
    DoublyLinkedList li;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        li.pushBack(elem);
    }
    int value;
    cin >> value;
    if (!li.count(value))
    {
        cout << "Deletion not possible";
    }
    else
    {
        li.deletion(value);
        li.display();
    }
    return 0;
}