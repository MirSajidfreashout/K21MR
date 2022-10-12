#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tail = head;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}
void deleteLast()
{
    struct Node *temp = head, *prev_node;
    while (temp->next != NULL)
    {
        prev_node = temp;
        temp = temp->next;
    }
    free(temp);
    prev_node->next = NULL;
}
void displayFor()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void displayBack()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != head->prev)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
int main()
{
    int n, data;
    scanf("%d", &n);
    if (n >= 5 && n < 15)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);
            push(data);
        }
        deleteLast();
        displayFor();
        printf("\n");
        displayBack();
    }
    else
    {
        printf("Invalid Input");
        return 0;
    }
    return 0;
}