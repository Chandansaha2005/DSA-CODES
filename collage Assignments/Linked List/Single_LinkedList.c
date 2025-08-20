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
    count = 0;
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
void display()
{
    struct Node *p;
    p = head;
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
}
