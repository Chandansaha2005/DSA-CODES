#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int pri_que[MAX];
int f = -1, r = -1;

void insert(int data);
void del(int data);
void display_pqueue();

void main()
{
    int n, ch;
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &n);
            del(n);
            break;
        case 3:
            display_pqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

void insert(int data)
{
    if (r >= MAX - 1)
    {
        printf("\nQueue overflow, no more elements can be inserted");
        return;
    }

    if (f == -1 && r == -1)
    {
        f = r = 0;
        pri_que[r] = data;
    }
    else
    {
        int i, j;
        for (i = 0; i <= r; i++)
        {
            if (data >= pri_que[i])
            {
                for (j = r + 1; j > i; j--)
                    pri_que[j] = pri_que[j - 1];
                pri_que[i] = data;
                r++;
                display_pqueue();
                return;
            }
        }
        pri_que[++r] = data;
    }
    display_pqueue();
}

void del(int data)
{
    if (f == -1 && r == -1)
    {
        printf("\nQueue is empty, no elements to delete");
        return;
    }

    int i;
    for (i = f; i <= r; i++)
    {
        if (pri_que[i] == data)
        {
            for (; i < r; i++)
                pri_que[i] = pri_que[i + 1];
            r--;
            if (r < f)
                f = r = -1;
            display_pqueue();
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}

void display_pqueue()
{
    if (f == -1 && r == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nPriority Queue: ");
    for (int i = f; i <= r; i++)
        printf("%d ", pri_que[i]);
}
