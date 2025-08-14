#include <stdio.h>
#include <stdlib.h>
#define MAX 30
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
    char infix[MAX], post[MAX], ch;
    do
    {
        printf("\nEnter 1 For Infix To Postfix Conversion.\n");
        printf("Enter 2 For Postfix Evaluation.\n");
        printf("Enter 3 For Exit");
        scanf("Enter Your Choice = ");
        scanf(" %c", &ch);
        switch (ch)
        {
        case '1':
            printf("Enter Infix Expression = ");
            scanf(" %s", &infix);
            printf(infix);
            break;

        default:
            break;
        }
    } while (1);
}