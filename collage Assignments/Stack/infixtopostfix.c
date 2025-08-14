#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 30
char stack[MAX], top = -1;
void push(char value)
{
    stack[++top] = value;
}
char pop()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW!!!\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int isoparator(char op)
{
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}
void infixToPost(char infix[], char post[])
{
    int i = 0, j = 0;
    char sml;
    while (post[i] != '\0')
    {
        sml = post[i];
        if (sml == '(')
            push(sml);
        else if (isalnum(sml))
            post[j++] = sml;
        else if (sml == ')')
        {
            while (stack[top] != '(')
            {
                post[j++] = pop();
            }
            pop();
        }
        else if (isoparator(sml) != 0)
        {
            while (isoparator(stack[top]) >= isoparator(sml) && stack[top] != '(')
            {
                post[j++] = pop();
            }
            pop();
        }
        else
        {
            printf("WORNG EXPRESSION!!\n");
            return;
        }
        i++;
    }
    while (top != -1)
    {
        post[j++] = pop();
    }
    post[j] = '\0';
}
void main()
{
    char infix[MAX], post[MAX];
    printf("Enter Infix Expression = ");
    scanf(" %s", &infix);
    infixToPost(infix, post);
    for (int i = 0; post[i] != '\0'; i++)
    {
        printf(" %c", post[i]);
    }
}