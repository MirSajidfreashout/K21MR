#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int emp_id, sal;
    string name;
    Node *next;
};
Node *head = NULL;
void Insert_Details(string name, int data1, int data2)
{
    Node *ptr;
    Node *newNode = new Node;
    newNode->name = name;
    newNode->emp_id = data1;
    newNode->sal = data2;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
void Emp_Details(int key)
{
    Node *ptr;
    ptr = head;
    int flag = 0;
    while (ptr != NULL)
    {
        if (ptr->emp_id == key)
        {
            cout << ptr->name << " " << ptr->sal << endl;
            flag++;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        cout << "Employee does not exist";
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int emp_id, sal;
        string name;
        cin >> name >> emp_id >> sal;
        Insert_Details(name, emp_id, sal);
    }
    int key;
    cin>>key;
    Emp_Details(key);

    return 0;
}