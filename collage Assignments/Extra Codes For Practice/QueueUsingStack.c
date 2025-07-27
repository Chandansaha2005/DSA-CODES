// WAP to implement Queue using Stack
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void enqueue();                                       // function declaration
void dequeue();                                       // function declaration
void display();                                       // function declaration//peep()   peek()
int stack[SIZE], queue[SIZE], s_top = -1, q_top = -1; // variable declaration
int value, choice;
void main()
{
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. enqueue\n2. dequeue\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(); // func. calling
            break;
        case 2:
            dequeue(); // func. calling
            break;
        case 3:
            exit(0);
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void queuefication(int stack[])
{
    int top = s_top;
    q_top = -1;
    for (int i = 0; i <= s_top; i++)
    {
        queue[++q_top] = stack[top--];
        printf("q_top = %d", q_top);
    }
}
void stackfication(int queue[])
{
    int top = q_top;
    s_top = -1;
    for (int i = 0; i <= q_top; i++)
    {
        stack[++s_top] = queue[top--];
    }
}
void enqueue() // func. definition
{
    if (s_top == SIZE - 1 && q_top == SIZE - 1)
    {
        printf("\nStack is Full!!! Insertion is not possible!!!");
        return;
    }
    else
    {
        printf("Enter the No. = ");
        scanf("%d", &value);
        stack[++s_top] = value;
        printf("\nInsertion success!!!");
        queuefication(stack);
        display();
    }
}
void dequeue() // func. definition
{
    if (s_top == -1 && q_top == -1)
    {
        printf("\nStack is Empty!!! Deletion is not possible!!!");
        return;
    }
    else
    {
        printf("\nDeleted : %d\n", queue[q_top--]);
        stackfication(queue);
        display();
    }
}
void display() // func. definition
{
    int i;
    if (s_top == -1 && q_top == -1)
    {
        printf("Stack is empty \n");
        return;
    }
    else
    {
        printf("Stack is : \n");
        for (i = 0; i <= s_top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
