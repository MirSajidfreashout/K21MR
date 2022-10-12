#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *head = NULL;
void insert(int d)
{
    node *ptr;
    node *n = new node;
    n->data = d;
    n->next = NULL;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void del()
{
    node *ptr;
    node *prev;
    int z = 0;
    if (head == NULL)
    {
        exit(0);
    }
    while ((head->data) % 2 == 0)
    {
        head = head->next;
        z++;
        if (head == NULL)
        {
            exit(0);
            cout << "No even number present";
        }
    }
    ptr = head;
    prev = head;
    while (ptr->next != NULL)
    {
        if ((ptr->data) % 2 == 0)
        {
            (prev->next) = (ptr->next);
            z++;
            ptr = ptr->next;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if ((prev->data) % 2 == 0)
    {
        prev->next = NULL;
    }
    if (z == 0)
    {
        cout << "No even number present";
        exit(0);
    }
}

void traverse()
{
    node *ptr;
    if (head == NULL)
    {
        exit(0);
    }
    ptr = head;

    while (ptr->next != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int x = 0;
    while (x != -1)
    {
        cin >> x;
        insert(x);
    }
    del();
    traverse();
    return 0;
}