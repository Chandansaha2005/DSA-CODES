// WAP to implement queue using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // array size will be fixed for 3 no.
int queue_array[MAX], rear = -1, front = -1;
void enqueue(); // func. declaration--> enqueue
void dequeue(); // func. declaration--> dequeue
void display(); // func. declaration
void main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(); // func. calling
            break;
        case 2:
            dequeue(); // calling
            break;
        case 3:
            exit(0);
        default:
            printf("\nWRONG CHOICE!!!\n");
        }
    }
}
void enqueue() // func. definition
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow \n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        int add;
        printf("Insert the element in queue : ");
        scanf("%d", &add);
        rear = rear + 1;
        queue_array[rear] = add;
        display();
    }
}
void dequeue() // func. definition
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Deleted : %d\n", queue_array[front]);
        front++;
        display();
    }
}
void display() // func. definition
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty \n");
        return;
    }
    else
    {
        int i;
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
