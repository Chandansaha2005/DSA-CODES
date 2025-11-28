// PREFIX TO INFIX CONVERSATION 👇
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

void push(char item[])
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        strcpy(stack[++top], item);
    }
}

void pop(char popped[])
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        strcpy(popped, stack[top--]);
    }
}

int isOperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    {
        return 1;
    }
    return 0;
}

void prefixToInfix(char prefix[], char infix[])
{
    int i, len = strlen(prefix);
    char operand1[MAX_SIZE], operand2[MAX_SIZE], temp[MAX_SIZE];

    for (i = len - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            pop(operand1);
            pop(operand2);
            sprintf(temp, "(%s%c%s)", operand1, prefix[i], operand2);
            push(temp);
        }
        else
        {
            sprintf(temp, "%c", prefix[i]);
            push(temp);
        }
    }
    strcpy(infix, stack[top]);
}

int main()
{
    char prefix[MAX_SIZE], infix[MAX_SIZE];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix, infix);
    printf("Infix expression: %s\n", infix);

    return 0;
}