#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
};
Node *head = NULL;
void insert(char data)
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
void deleteVowel()
{
    Node *ptr;
    Node *prev;
    int count = 0;
    if (head == NULL)
    {
        exit(0);
    }
    while ((head->data == 'a') ||
           (head->data == 'e') ||
           (head->data == 'i') ||
           (head->data == 'o') ||
           (head->data == 'u'))
    {
        head = head->next;
        count++;
        if (head == NULL)
        {
            exit(0);
            cout << "No odd number present";
        }
    }
    ptr = head;
    prev = head;
    while (ptr != NULL)
    {
        if ((ptr->data == 'a') ||
            (ptr->data == 'e') ||
            (ptr->data == 'i') ||
            (ptr->data == 'o') ||
            (ptr->data == 'u'))
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
    if ((prev->data == 'a') ||
        (prev->data == 'e') ||
        (prev->data == 'i') ||
        (prev->data == 'o') ||
        (prev->data == 'u'))
    {
        prev->next = NULL;
    }
    if (count == 0)
    {
        cout << "No vowel in linked list";
        exit(0);
    }
}
void traverse()
{
    Node* temp = head;
    if (!temp)
    {
        cout << "Empty List\n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << "";
        if (temp->next)
            cout << "-->";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    char x;
    while (cin >> x)
    {
        insert(x);
    }
    deleteVowel();
    traverse();
    return 0;
}