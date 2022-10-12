#include <bits/stdc++.h>
using namespace std;

#define MAX 100
class Queue
{
  int front = -1;
  int rear = -1;

public:
  char queue[MAX];
  bool enqueue(char x);
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

bool Queue::enqueue(char value)
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
    char y = queue[front];
    front = rear = -1;
    return y;
  }
  else
  {
    char x = queue[front++];
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
    {
      if (isdigit(queue[i]) == false && queue[i] != 44)
        cout << queue[i];
    }
  }
  cout << endl;
}

int main()
{
  Queue q;
  string elem;
  getline(cin, elem);

  for (auto i : elem)
  {
    q.enqueue(i);
  }

  q.display();

  return 0;
}
