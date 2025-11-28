// INFIX TO POSTFIX CONVERSATION 👇

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        stack[++top] = item;
    }
}

char pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

int isOperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        return 1;
    }
    return 0;
}

int precedence(char symbol)
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

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    push('(');

    while (infix[i] != '\0')
    {
        symbol = infix[i];

        if (symbol == '(')
        {
            push(symbol);
        }
        else if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9'))
        {
            postfix[j++] = symbol;
        }
        else if (isOperator(symbol))
        {
            while (precedence(stack[top]) >= precedence(symbol) && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            printf("Invalid infix expression\n");
            exit(1);
        }
        i++;
    }
    while (top > -1 && stack[top] != '(')
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}