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
    void pushBack(int val)
    {
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
    int largest()
    {
        int large = INT_MIN;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (large < ptr->data)
            {
                large = ptr->data;
            }
            ptr = ptr->next;
        }
        return large;
    }
    void del(int large)
    {
        if (head == nullptr)
            return;
        else if (head->data == large)
        {
            head = head->next;
        }
        Node *ptr = head;
        Node *prev = head;
        while (ptr != NULL)
        {
            if (ptr->data == large)
            {
                prev->next = ptr->next;
            }
            else
                prev = ptr;

            ptr = ptr->next;
        }
    }
    void display()
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    LinkedList li;
    int n, elem;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        li.pushBack(elem);
    }
    li.del(li.largest());
    li.display();

    return 0;
}