// Priority Queue
// wap to implement priority queue using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 4
void insert_by_priority();
void delete_by_priority();
void check(int);
void display_pqueue();
int pri_que[MAX];
int front = -1, rear = -1;
void main()
{
    int n, ch;
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_by_priority(); // calling
            break;
        case 2:
            delete_by_priority(); // calling
            break;
        case 3:
            display_pqueue(); // calling
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

void insert_by_priority()
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    int data;
    printf("\nEnter value to be inserted : ");
    scanf("%d", & data);       // n=15 10
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data); // calling
    rear++;          // 1
    display_pqueue();
}
void check(int data)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i]) // 10>=15
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data; //
}
void delete_by_priority()
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    int data;
    printf("\nEnter value to delete : ");
    scanf("%d", &data);       // n=50
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++) // i=0  0<0 i++
            {
                pri_que[i] = pri_que[i + 1];
            }
            pri_que[i] = 0;
            rear--; //-1
            if (rear == -1)
                front = -1;
            return;
        }
    }
    display_pqueue();
    printf("\n%d not found in queue to delete", data);
}
void display_pqueue()
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (i = front; i <= rear; i++)
    {
        printf(" %d ", pri_que[i]);
    }
}
