# Singly Linked List

## Insertion at the beginning of the list

```cpp
#include <bits/stdc++.h>
using namespace std;
class Node // general Node declaration
{
public:
	int data;
	Node *next;
};

Node *head = NULL; // global head pointer

void insertAtHead(int data)
{
	Node *newNode = new Node;
	newNode->data = data; // insert data into data part of node
	newNode->next = head; // point head ot next of the added node
	head = newNode;		  // head will contain pointer of the newly added node
}

// function to print the list
void printList()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	// inserting element in the front of the list
	insertAtHead(6);
	insertAtHead(5);
	insertAtHead(4);
	insertAtHead(3);
	
	printList(); // function call to print the list

	return 0;
}
```

---

## Insert at the end of the list

```cpp
#include <bits/stdc++.h>
using namespace std;
class Node // general Node declaration
{
public:
	int data;
	Node *next;
};

Node *head = NULL; // global head pointer

void insertAtEnd(int data)
{
	Node *newNode = new Node;
	newNode->data = data; // insert data into data part of node
	newNode->next = NULL; // assign NULL to the next of the node

	if(head == NULL){
			head = newNode; // if list is empty then make new node as head
	}
	// else if list is not empty then traverse to the end of the list and then add the element
	else{
		Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode; // change the next of the last node to the new node
	}
}

// function to print the list
void printList()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	// inserting element in the end of the list
	insertAtEnd(6);
	insertAtEnd(5);
	insertAtEnd(4);
	insertAtEnd(3);
	
	printList(); // function call to print the list

	return 0;
}
```

---

## Insertion at a given position

```cpp
#include <bits/stdc++.h>
using namespace std;
class Node // general Node declaration
{
public:
	int data;
	Node *next;
};

Node *head = NULL; // global head pointer

void insertAtEnd(int data)
{
	Node *newNode = new Node;
	newNode->data = data; // insert data into data part of node
	newNode->next = NULL; // assign NULL to the next of the node

	if(head == NULL){
		head = newNode; // if list is empty then make new node as head
	}
	// else if list is not empty then traverse to the end of the list and then add the element
	else{
		Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode; // change the next of the last node to the new node
	}
}

// function to insert data at a given position
void insertAtPos(int data, int pos)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;

	// if position is 1 then insert at head
	if(pos == 1){
		newNode->next = head;
		head = newNode;
	}	
	// else iterate to find the given position and then insert
	else{
		Node *temp = head;
		for(int i = 1; i < pos - 1; i++){
			if(temp != NULL){
				temp = temp->next;
			}
		}

		if(temp != NULL){
			newNode->next = temp->next;
			temp->next = newNode;
		}
		else{
			cout<<"The prev node is null.";
		}
	}
}

// function to print the list
void printList()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	// inserting element in the end of the list
	insertAtEnd(6);
	insertAtEnd(5);
	insertAtEnd(4);
	insertAtEnd(3);
	
	// insert element at a given position
	insertAtPos(100,2);
	insertAtPos(499,4);

	printList(); // function call to print the list

	return 0;
}
```
---
## Insertion after a given Node
```cpp
#include <bits/stdc++.h>
using namespace std;
class Node // general Node declaration
{
public:
    int data;
    Node *next;
};

Node *head = NULL; // global head pointer

void insertAtEnd(int data)
{
    Node *newNode = new Node;
    newNode->data = data; // insert data into data part of node
    newNode->next = NULL; // assign NULL to the next of the node

    if (head == NULL)
    {
        head = newNode; // if list is empty then make new node as head
    }
    // else if list is not empty then traverse to the end of the list and then add the element
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode; // change the next of the last node to the new node
    }
}

// function to print the list
void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//function to insert node after a given value
void insertAfterNode(int key, int data)
{
    Node *newNode = new Node; //make new node
    newNode->data = data;
    Node *temp = head;
    while (temp != NULL) //iterate till the end of list
    {
        if (head == NULL) //if list is empty
        {
            insertAtEnd(data); //insert data at end (single element only)
        }
        else
        {
            if (temp->data == key) //if given node is found
            {
                // (this given sequence MUST be followed)
                // point new node to the next of the key node
                newNode->next = temp->next;
                // point key to the new node
                temp->next = newNode;
            }
            temp = temp->next; // move pointer forward
        }
    }
}

int main()
{
    // inserting element in the end of the list
    insertAtEnd(6);
    insertAtEnd(5);
    insertAtEnd(4);
    insertAtEnd(3);

    insertAfterNode(5, 99); //function call to insert 99 after node containing value 5

    printList(); // function call to print the list
    return 0;
}
```
---
# Doubly Linked List
## Insertion at the beginning of the list
```cpp
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
void pushFront(int data)
{
    Node *newNode = new Node;
    if (head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = data;
        head = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    pushFront(1);
    pushFront(2);
    pushFront(3);
    pushFront(4);
    printList();
    return 0;
}
```
---
## Insertion at the end of the list
```cpp
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;   // data part of the node
    Node *next; // make next pointer to point to the next node
    Node *prev; // make previous pointer to point to the previous node
};
Node *head = NULL; // global head pointer

// to push data into the end of the DLL
void pushTail(int data)
{
    Node *newNode = new Node;
    Node *tail = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
}

// to display the DLL
void display()
{
    Node *temp = head;   // assign temp pointer to the head
    while (temp != NULL) // iterate as long as the temp pointer is not NULL
    {
        cout << temp->data << " "; // display data part of the node
        temp = temp->next;         // move forward in the DLL
    }
}

//driver function
int main()
{
    // function to insert data into the tail of the DLL
    pushTail(7);
    pushTail(8);
    pushTail(3);
    pushTail(9);
    pushTail(1);
    pushTail(3);
    display();
    return 0;
}
```
---
