#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
};
Node *head = NULL;
void pushQueue(string car)
{
    Node *newNode = new Node;
    newNode->data = car;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void popQueue()
{
Node *temp = head;
string car;
car = temp->data;
head = head->next;
pushQueue(car);
}
void printHead()
{
    Node *temp = head;
    cout<<temp->data;
}
void printList()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}
int main()
{
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        string car;
        cin >> car;
        pushQueue(car);
    }
    popQueue();
    printList();
    popQueue();
    printList();
    popQueue();
    printList();
    printHead();
}