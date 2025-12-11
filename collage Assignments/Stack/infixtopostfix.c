#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char value)
{
    stack[++top] = value;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int prec(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int isoperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

void infixtopost(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (symbol == '(')
            push(symbol);
        else if (isalnum(symbol))
            postfix[j++] = symbol;
        else if (symbol == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else if (isoperator(symbol))
        {
            while (prec(stack[top]) >= prec(symbol) && stack[top] != '(')
                postfix[j++] = pop();
            push(symbol);
        }
        else
        {
            printf("Wrong Expression\n");
            return;
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void main()
{
    char infix[SIZE], postfix[SIZE];
    int i;
    printf("Enter the Infix Expression = ");
    scanf("%s", infix);
    infixtopost(infix, postfix);
    printf("Postfix Expression = ");
    for (i = 0; postfix[i] != '\0'; i++)
    {
        printf(" %c", postfix[i]);
    }
}