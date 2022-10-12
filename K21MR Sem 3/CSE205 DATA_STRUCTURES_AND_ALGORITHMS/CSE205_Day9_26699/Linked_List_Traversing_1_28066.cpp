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
class linkedlist
{
public:
    int size = 0;
    Node *head = NULL;
    void push(int d)
    {
        size++;
        if (head == nullptr)
        {
            head = new Node(d);
            return;
        }
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(d);
    }
    void sum()
    {
        int sum = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                sum += temp->data;
            }
            temp = temp->next;
        }
        if (sum)
            cout << sum;
        else
            cout << "No Even numbers Present";
    }
};
int main()
{
    linkedlist ll;
    int n;
    cin >> n;
    if (n <= 0)
        return 0;
    else
    {
        while (n--)
        {
            int x;
            cin >> x;
            ll.push(x);
        }
        ll.sum();
    }
    return 0;
}