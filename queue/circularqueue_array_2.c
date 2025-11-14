#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Inserted %d\n", data);
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    return data;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    return 0;
}
