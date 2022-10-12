#include <bits/stdc++.h>
using namespace std;

#define yaha_se  \
      int main() \
      {
#define yaha_tak \
      return 0;  \
      }
#define andar_daalo cin
#define bahar_nikalo cout
#define sarkaari public
#define khaali void
#define poornaank int
#define dori string
#define agar if
#define jab_tak while
#define tara *
#define ka ->
#define kaksha class
#define yaha this
#define rikt NULL
#define shoonya_nikalo return 0
#define nikal_do return

kaksha Node
{
sarkaari:
      dori data;
      Node tara next = rikt;
      Node(dori data)
      {
            yaha ka data = data;
      }
};

kaksha Stack
{
sarkaari:
      Node tara head = rikt;
      khaali daalo(dori value)
      {
            Node *n = new Node(value);
            n ka next = head;
            head = n;
      }

      khaali nikalo()
      {
            Node tara ptr = head;
            agar(head == rikt)
            {
                  bahar_nikalo << "Empty Box";
                  nikal_do;
            }
            jab_tak(ptr ka next != rikt)
            {
                  bahar_nikalo << ptr ka data << "->";
                  ptr = ptr ka next;
            }
            bahar_nikalo << ptr ka data;
      }
};

yaha_se
Stack s1;
poornaank n;
andar_daalo >> n;
agar(n > 6)
{
      bahar_nikalo << "Full Box";
      shoonya_nikalo;
}
jab_tak(n--)
{
      dori padaarth;
      andar_daalo >> padaarth;
      s1.daalo(padaarth);
}
s1.nikalo();

yaha_tak