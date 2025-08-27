#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
int count = 0;
void createNode(int n)
{
    struct Node *newNode, *temp;
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Element = ");
        scanf("%d", &newNode->data);
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the Element = ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)), *temp;
    printf("\nEnter the Element = ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display()
{
    struct Node *p;
    p = head;
    if (p == NULL)
        printf("\nEmpty Linked List\n");
    else
    {
        while (p != NULL)
        {
            printf("%d --> ", p->data);
            p = p->next;
            if (p == NULL)
                printf("NULL\n");
        }
    }
}
void main()
{
    display();
    createNode(5);
    display();
    insertAtBeg();
    display();
    insertAtEnd();
    display();
}