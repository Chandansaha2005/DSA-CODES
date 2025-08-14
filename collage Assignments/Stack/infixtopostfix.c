#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int stack[MAX], top = -1;
void display()
{
    if (top == -1)
    {
        printf("STACK EMPTY!!!");
        return;
    }
    printf("\nSTACK : ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("STACK OVERFLOW!!!\n");
        return;
    }
    stack[++top] = value;
    printf("%d Inserted\n", value);
    display();
}
int pop()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW!!!\n");
        return -1;
    }
    return stack[top--];
}
void main()
{
    int choice, val, d;
    do
    {
        printf("\nPress 1 To PUSH\n");
        printf("Press 2 To POP\n");
        printf("Press 3 To DISPLAY\n");
        printf("Press 4 To EXIT\n");
        printf("Enter the Choice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Number To Push = ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            d = pop();
            if (d == -1)
            {
                printf("Insert Any Element\n");
                break;
            }
            else
                printf("%d deleted\n", d);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    } while (choice < 4);
}