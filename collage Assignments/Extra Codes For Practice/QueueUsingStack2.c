#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

// Enqueue operation
void enqueue(int value)
{
    if (top1 >= SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    stack1[++top1] = value;
    printf("Inserted %d\n", value);
}

int dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    if (top2 == -1)
    {
        while (top1 != -1)
        {
            stack2[++top2] = stack1[top1--];
        }
    }
    int val = stack2[top2--];
    return val;
}
void display()
{
    printf("Queue contents:\n");
    if (top2 != -1)
    {
        for (int i = top2; i >= 0; i--)
            printf("%d ", stack2[i]);
    }
    if (top1 != -1)
    {
        for (int i = 0; i <= top1; i++)
            printf("%d ", stack1[i]);
    }
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty.");
    }
    printf("\n");
}

void main()
{
    int choice, val;
    while (1)
    {
        printf("\n*** MENU ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
        {
            int del = dequeue();
            if (del != -1)
                printf("Deleted: %d\n", del);
            break;
        }
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
