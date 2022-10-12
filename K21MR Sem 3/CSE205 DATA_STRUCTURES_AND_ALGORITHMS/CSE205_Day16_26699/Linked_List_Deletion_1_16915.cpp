#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int data)
{
    Node *temp;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteOdd()
{
    Node* ptr;
    Node* prev;
    int count = 0;
    if(head == NULL)
    {
        exit(0);
    }
    while((head->data)%2 != 0)
    {
        head = head->next;
        count++;
        if(head == NULL)
        {
            exit(0);
            cout<<"No odd number present";
        }
    }
    ptr = head;
    prev = head;
    while(ptr->next != NULL)
    {
        if((ptr->data)%2 != 0)
        {
            prev->next = ptr->next;
            count++;
            ptr = ptr->next;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if((prev->data)%2 != 0)
    {
        prev->next = NULL;
    }
    if(count == 0)
    {
        cout<<"No odd number present";
        exit(0);
    }
}
void traverse()
{
    Node *temp;
    if (head == NULL)
    {
        exit(0);
    }
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int x;
    while (x != -1)
    {
        cin >> x;
        insert(x);
    }
    deleteOdd();
    traverse();
    return 0;
}