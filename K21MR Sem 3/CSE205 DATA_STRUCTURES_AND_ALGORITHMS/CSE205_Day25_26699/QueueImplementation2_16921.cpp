#include <iostream>
using namespace std;

char myStack[10];
int front = -1, rear = -1, count = 0;

void insert(char c)
{
    if (count == 7)
    {
        cout << "OVERFLOW" << endl;
        exit(0);
    }
    if (rear == -1)
    {
        front++;
        rear++;
        myStack[rear] = c;
        count++;
    }
    else
    {
        rear++;
        myStack[rear] = c;
        count++;
    }
}

void delete_ch()
{
    rear--;
}

int main()
{
    int key;
    do
    {
        cin >> key;
        if (key == 1)
        {
            char x;
            cin >> x;
            insert(x);
        }
        if (key == 2)
        {
            delete_ch();
        }
    } while (key == 1 || key == 2);
    if (front == -1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << myStack[front] << endl;
    }
    if (rear == -1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << myStack[rear] << endl;
    }
    return 0;
}