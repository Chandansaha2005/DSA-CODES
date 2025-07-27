#include <stdio.h>
#include <stdlib.h>
#define max 3
char QUEUE[max];
int front = -1, rear = -1;
void ENQUEUE(char v)
{
    if (rear == max - 1)
    {
        printf("QUEUE OVERFLOW");
        exit(0);
    }
    else
    {
        QUEUE[++rear] = v;
        if (front == -1)
            front = 0;
    }
}
char DEQUEUE()
{
    if (front == -1 || front > rear)
    {
        printf("QUEUE UNDERFLOW");
        exit(0);
    }
    return QUEUE[front++];
}
void DISPLAY()
{
    if (front == -1 || front > rear)
    {
        printf("QUEUE UNDERFLOW");
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%c ", QUEUE[i]);
        }
    }
}
void main()
{
    printf("-----QUEUE-----");
    int c;
    char val;
    do
    {
        printf("\nPress 1 For ENQUEUE\nPress 2 For DEQUEUE\nPress 3 For DISPLAY\nPress 4 For EXIT\nEnter Your Choice = \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            // printf("Enter the Character to Insert in the QUEUE = ");
            // scanf("%s",&val);
            ENQUEUE('d');
            break;

        case 2:
            printf("Deleted Element = %c", DEQUEUE());
            break;

        case 3:
            printf("QUEUE = ", DEQUEUE());
            break;

        default:
            break;
        }
    } while (c < 4);
}