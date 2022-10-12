// The LPU named as Fees_Due_Record is maintaining the records of its student Fee details using a linked list where the following details of employees are maintained:

// Student Registration Number
// Name
// Due Fee
// The LPU is looking for an interface where they can search the details of student who have fee due more than 25000. You have to implement the solution for the same in the following function: void Insert_Details(int , string, int ) void Fees_Due_Details()
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int id, fee;
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
    newNode->fee = data2;
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
        if (ptr->fee > 25000)
        {
            cout << ptr->id << " " << ptr->name << " " << ptr->fee << endl;
            flag++;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        cout << "Students does not have fee due more than 25000";
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