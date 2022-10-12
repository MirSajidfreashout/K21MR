#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next = NULL;
    Node *prev = NULL;
    int data = -1;

    Node(int data, Node *prev = NULL, Node *next = NULL) : data(data), prev(prev), next(next){};
    Node(){};
};

class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int odd = 0;

    void push(int data);
    void remove()
    {
        if (head == NULL)
            return;
        while (head != NULL && head->data % 2)
        {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            odd++;
        }
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data % 2)
            {
                if (ptr->prev != NULL)
                {
                    ptr->prev->next = ptr->next;
                }
                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;
                odd++;
            }
            ptr = ptr->next;
        }
    };
};

void DoublyLinkedList ::push(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        tail = head;
        return;
    }

    Node *node = new Node(data, tail, NULL);
    tail->next = node;
    tail = node;
}

int main()
{
    int n, elem, size = 0;
    cin >> n;

    DoublyLinkedList list;
    while (cin >> elem)
    {
        list.push(elem);
        size++;
    }
    if (n != size)
    {
        cout << "Wrong Input.";
        return 0;
    }
    list.remove();
    if (list.odd)
        for (auto ptr = list.head; ptr != NULL; ptr = ptr->next)
            cout << ptr->data << ' ';
    else
        cout << "No student is having odd roll number.";
    return 0;
}