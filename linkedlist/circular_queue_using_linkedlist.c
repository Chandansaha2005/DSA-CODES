#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    printf("Inserted %d\n", x);
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    int val;
    if (front == rear)
    {
        val = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        val = temp->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    return val;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue: ");
    while (temp->next != front)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void main()
{
    int choice, val;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1)
                printf("Dequeued: %d\n", val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
