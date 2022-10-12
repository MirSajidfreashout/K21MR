#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      string data;
      Node *next = NULL;
      Node(string data)
      {
            this->data = data;
      }
};

class Stack
{
public:
      Node *head = NULL;

      void pushBack(string value)
      {
            Node *n = new Node(value);
            n->next = head;
            head = n;
      }
      void pop()
      {
            if (head == NULL)
            {
                  cout << "Underflow";
                  return;
            }
            head = head->next;
      }

      void display()
      {
            Node *ptr = head;
            while (ptr != NULL)
            {
                  string str = ptr->data;
                  reverse(str.begin(), str.end());
                  if (str == ptr->data)
                  {
                        cout << "Palindrome";
                  }
                  else
                  {
                        cout << "Not Palindrome";
                  }

                  ptr = ptr->next;
            }
            cout << endl;
      }
};

int main()
{
      Stack s1;
      string elem;
      while (cin >> elem)
      {
            s1.pushBack(elem);
      }
      s1.display();
      return 0;
}