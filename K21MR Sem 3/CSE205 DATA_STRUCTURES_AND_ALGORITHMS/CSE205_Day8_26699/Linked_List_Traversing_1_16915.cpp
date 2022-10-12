// Write a program to display the count of nodes having odd number in a given singly linked list. If no odd number is present in the linked list then display "No odd number present". Linked list will contain only positive number, if you do not want add next number to the linked list then enter -1.

// Input Format

// Enter a list of integers ending with -1.

// Constraints

// Linked lis should not be empty

// Output Format

// Display the count of nodes having odd number in a given singly linked list.
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
};

int main()
{
    int elem;
    LinkedList ll;
    while (cin >> elem)
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