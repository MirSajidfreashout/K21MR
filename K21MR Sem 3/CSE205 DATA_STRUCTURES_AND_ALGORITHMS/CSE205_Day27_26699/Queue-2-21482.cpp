#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int front = -1, rear = -1;

void enque(int x, int a[])
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    a[rear] = x;
}

void deque()
{
    front++;
}

int main()
{
    int n, op, x;
    cin >> n;
    cin >> op;
    int a[op * n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        enque(x, a);
    }
    for (int i = 0; i < op; i++)
    {
        cin >> x;
        if (x == 0)
        {
            deque();
        }
        else if (x == 1)
        {
            enque(a[front], a);
            deque();
        }
    }
    for (int i = front; i <= rear; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}