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

    // Insert Node at given index
    void insert(int index, int val)
    {
        Node *node = new Node(val);
        if (head == nullptr && index == 0)
        {
            head = node;
            size++;
            return;
        }
        else if (index == 0)
        {
            node->next = head;
            head = node;
            size++;
            return;
        }
        int i = 1;
        Node *ptr = head;
        for (; i < index; i++)
            ptr = ptr->next;
        node->next = ptr->next;
        ptr->next = node;
        size++;
    }

    // Insert element after given value
    void insert_after(int refernce, int val)
    {
        if (head == nullptr)
            return;
        Node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data == refernce)
            {
                Node *temp = new Node(val);
                temp->next = ptr->next;
                ptr->next = temp;
                size++;
                if (refernce == val)
                    ptr = ptr->next;
            }
            ptr = ptr->next;
        }
    }

    // Removes head of list
    void pop_front()
    {
        if (head == nullptr)
            return;
        head = head->next;
        size--;
    }

    // Deletes given value from list
    void pop(int val)
    {
        if (head == nullptr)
            return;
        else if (head->data == val)
        {
            head = head->next;
            size--;
        }
        Node *ptr = head;

        while (ptr->next != NULL && ptr->next->data != val)
            ptr = ptr->next;
        if (ptr->next != nullptr)
        {
            ptr->next = ptr->next->next;
            size--;
        }
    }
    // Deletes all occurences
    void pop_all(int val)
    {
        if (head == nullptr)
            return;
        while (head->data == val)
        {
            head = head->next;
            size--;
        }
        Node *ptr = head;
        Node *prev = head;
        while (ptr != NULL)
        {
            if (ptr->data == val)
            {
                prev->next = ptr->next;
                size--;
            }
            else
                prev = ptr;

            ptr = ptr->next;
        }
    }

    // deletes given index from list
    void erase(int index)
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
    int elem;
    LinkedList ll;
    while ((cin >> elem) != -1)
    {
        if (elem != -1)
            ll.push(elem);
    }
    int odd = 0;
    for (auto ptr = ll.head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data % 2)
            odd++;
    }
    if (odd)
        cout << odd;
    else
        cout << "No odd number present";
    return 0;
}
