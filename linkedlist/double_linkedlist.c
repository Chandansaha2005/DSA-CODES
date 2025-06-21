// double linked list - edited
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} N;
N *head, *temp, *newNode;
int i, x;
// struct Node N;
void createList(int);
void TraverseForward();
void insertatbeg();
void insertatend();
void insertatspecific();
void delatbeg();
void delatend();
void delatspecific();
int count = 0;
void main()
{
    while (1) // for(;;)
    {
        printf("\nPress 1 for Create\nPress 2 for Display\nPress 4 for Insert at beginning\nPress 5 for Insert at End\nPress 6 for Insert at Specific\nPress 7 for Delete at Beginning\nPress 8 for Delete at End\nPress 9 for Delete at Specific\n");
        int ch, n;
        printf("Enter the Choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Range = ");
            scanf("%d", &n);
            createList(n); // calling
            break;
        case 2:
            TraverseForward(); // calling
            break;
        case 4:
            insertatbeg(); // calling
            break;
        case 5:
            insertatend(); // calling
            break;
        case 6:
            insertatspecific(); // calling
            break;
        case 7:
            delatbeg(); // calling
            break;
        case 8:
            delatend(); // calling
            break;
        case 9:
            delatspecific(); // calling
            break;
        default:
            exit(0);
        }
    }
}
void createList(int n)
{
    int i, x;
    head = (N *)malloc(sizeof(N));
    printf("Enter the No.= ");
    scanf("%d", &x);
    if (head == NULL)
    {
        printf("Memory can't be deleted");
        return;
    }
    else
    {
        head->data = x;
        head->prev = NULL;
        head->next = NULL;
        temp = head;
        count++;
        for (i = 2; i <= n; i++)
        {
            newNode = (N *)malloc(sizeof(N));
            printf("Enter the No.= ");
            scanf("%d", &x);
            newNode->data = x;
            newNode->prev = temp;
            newNode->next = NULL;
            temp->next = newNode;
            count++;
            temp = newNode;
        }
    }
    TraverseForward();
}
void TraverseForward()
{
    N *p;
    p = head;
    printf("list = \n");
    while (p->next != NULL)
    {
        printf("Value = %d Address = %u\n", p->data, p);
        p = p->next;
    }
    printf("Value = %d Address = %u\n", p->data, p);
    /*struct Node *q;
    q=p;*/
    printf("reverse list=\n");
    while (p != NULL)
    {
        printf("Value = %d Address = %u\n", p->data, p);
        p = p->prev;
    }
    printf("\nTotal nodes= %d ", count);
}
void insertatbeg()
{
    int x;
    newNode = (N *)malloc(sizeof(N));
    printf("Enter the data: ");
    scanf("%d", &x);
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    count++;
    TraverseForward();
}
void insertatend()
{
    int x;
    newNode = (N *)malloc(sizeof(N));
    printf("Enter the data to insert at the end: ");
    scanf("%d", &x);
    newNode->data = x;
    // newNode->prev=temp;
    newNode->next = NULL;
    N *p;
    p = head;
    while (p->next != NULL)
        p = p->next;
    newNode->prev = p;
    p->next = newNode;
    count++;
    TraverseForward();
}
void insertatspecific()
{
    int x, pos;
    N *p, *q;
    p = head;
    printf("Enter the position to insert the data: ");
    scanf("%d", &pos);
    if (pos == 1)
        insertatbeg();
    else if (pos == count + 1)
        insertatend();
    else if (pos > count + 1 || pos <= 0)
        return;
    else
    {
        for (i = 1; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = (N *)malloc(sizeof(N));
        printf("Enter the data: ");
        scanf("%d", &x);
        q = q->next;
        q->data = x;
        q->prev = p->prev;
        q->next = p;
        p->prev = q;
        count++;
        TraverseForward();
    }
}
void delatbeg()
{
    N *p;
    p = head;
    printf("Deleted Element = %d Address = %u\n", p->data, p);
    head = head->next;
    free(p);
    head->prev = NULL;
    --count;
    TraverseForward();
}
void delatend()
{
    N *tmp;
    tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    printf("Deleted Element = %d Address = %u\n", tmp->data, tmp);
    tmp->prev->next = NULL;
    free(tmp);
    --count;
    TraverseForward();
}
void delatspecific()
{
    int i, pos;
    N *del, *temp1, *q;
    printf("\nEnter the Position =");
    scanf("%d", &pos);
    if (pos == 1)
        delatbeg();
    else if (pos == count)
        delatend();
    else if (pos > count || pos <= 0)
        return;
    else
    {
        del = head;
        for (i = 1; i < pos; i++)
        {
            temp1 = del;
            del = del->next;
        }
        q = del->next;
        printf("Deleted element = %d address = %u\n", del->data, del);
        free(del);
        temp1->next = q;
        q->prev = temp1;
        --count;
        TraverseForward();
    }
}
