#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int stack[MAX], top = -1;
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
void display()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW!!!");
        return;
    }
    printf("STACK : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}
void main()
{
    int choice, val, d;
    printf("Press 1 To PUSH\n");
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

    default:
        break;
    }
}