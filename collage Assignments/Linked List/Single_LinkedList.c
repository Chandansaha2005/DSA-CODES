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
   struct Node * newNode , *temp;
   int x,i;
   head = NULL
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
