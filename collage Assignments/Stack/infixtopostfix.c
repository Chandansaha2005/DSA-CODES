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
    char infix[MAX] , post[MAX]
}