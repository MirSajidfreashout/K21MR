#include <bits/stdc++.h>
using namespace std;

#define MAX 100
class Queue
{
    int front = -1;
    int rear = -1;

public:
    int queue[MAX];
    bool enqueue(int x);
    int dequeue();
    void showfront();
    void display();
    bool isEmpty();
};

bool Queue::isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

bool Queue::enqueue(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full";
        return false;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        return true;
    }
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;

        return 0;
    }
    else if (front == rear)
    {
        int y = queue[front];
        front = rear = -1;
        return y;
    }
    else
    {
        int x = queue[front++];
        return x;
    }
}

void Queue::showfront()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
        cout << queue[front];
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    int n;
    cin >> n;
    while (n--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int elem;
            cin >> elem;
            q.enqueue(elem);
        }
        else
            cout << q.dequeue() << " ";
    }
    return 0;
}