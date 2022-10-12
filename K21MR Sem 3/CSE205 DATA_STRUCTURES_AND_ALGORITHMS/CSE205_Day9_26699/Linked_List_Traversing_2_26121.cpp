// An IT Company name Digital Solution Employee named as ** Employee_Record** is maintaining the records of its employee details using a linked list where the following details of employees are maintained:

// Employee id
// Employee Name
// Annual Salary
// The Digital Solution is looking for an interface where they can get the details of Employee who is getting annual salary more than 500000( >5 lakh).

// You have to implement the solution for the same in the following function:

// void Insert_Details () void Emp_Details()
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int id, sal;
    string name;
    Node *next;
};
Node *head = NULL;
void Insert_Details(int data1, string name, int data2)
{
    Node *ptr;
    Node *newNode = new Node;
    newNode->id = data1;
    newNode->name = name;
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
void Emp_Details()
{
    Node *ptr;
    ptr = head;
    int flag = 0;
    while (ptr != NULL)
    {
        if (ptr->sal > 500000)
        {
            cout << ptr->id << " " << ptr->name << " " << ptr->sal << endl;
            flag++;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        cout << "No Employee have salary more than 500000";
}
int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        string name;
        cin >> x >> name >> y;
        Insert_Details(x, name, y);
    }
    Emp_Details();

    return 0;
}