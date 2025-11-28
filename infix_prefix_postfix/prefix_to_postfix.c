// PREFIX TO POSTFIX CONVERSATION 👇

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

char str[MAX], stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '(':
    case ')':

        return 1;
    }
    return 0;
}

void prefixToPostfix()
{
    int n, i, j = 0;
    char c[20];
    char a, b, op;

    printf("Enter the prefix expression\n");
    scanf("%s", str);

    n = strlen(str);

    for (i = 0; i < MAX; i++)
        stack[i] = '\0';

    printf("Postfix expression is:\t");

    for (i = 0; i < n; i++)
    {
        if (isOperator(str[i]))
        {
            push(str[i]);
        }
        else
        {
            c[j++] = str[i];
            while ((top != -1) && (stack[top] == '#'))
            {
                a = pop();
                c[j++] = pop();
            }
            push('#');
        }
    }
    c[j] = '\0';

    for (i = 0; i < j; i++)
        printf("%c", c[i]);
}

int main()
{
    prefixToPostfix();
    return 0;
}