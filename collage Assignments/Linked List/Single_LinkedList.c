#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
int count = 0, tempo;
void createlist(int n)
{
    struct Node *newNode, *temp;
    int x, i;
    head = NULL;
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the number = ");
        scanf("%d", &x);
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        count++;
    }
}
void insertAtBeg()
{
    struct Node *beg = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The Number = ");
    scanf("%d", &beg->data);
    beg->next = head;
    head = beg;
    count++;
}
void insertAtSpecific(int pos)
{
    struct Node *newNode, *temp = head, *prev;
    int x;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The Number = ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            prev->next = temp;
            temp = temp->next;
        }
        prev->next = newNode;
        newNode->next = temp;
    }
    count++;
}
void insertAtEnd()
{
    struct Node *end, *temp = head;
    int x;
    end = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter The Number = ");
    scanf("%d", &end->data);
    end->next = NULL;
    if (head == NULL)
    {
        head = end;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = end;
    }
    count++;
}
void display()
{
    struct Node *p;
    p = head;
    if (p == NULL)
    {
        printf("Linked List Empty");
        return;
    }
    printf("\n------- :Linked List: -------\n");
    while (p != NULL)
    {
        printf("Value = %d Address = %u\n", p->data, p);
        p = p->next;
    }
}
void main()
{
    createlist(2);
    display();
    insertAtBeg();
    display();
    insertAtEnd();
    display();
    insertAtSpecific(2);
    display();
}
