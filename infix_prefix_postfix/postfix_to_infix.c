// POSTFIX TO INFIX 
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

void postfixToInfix(char postfix[], char infix[])
{
    int i = 0, len = strlen(postfix);
    char operand1[MAX_SIZE], operand2[MAX_SIZE], temp[MAX_SIZE];

    for (i = 0; i < len; i++)
    {
        if (isOperator(postfix[i]))
        {
            pop(operand2);
            pop(operand1);
            sprintf(temp, "(%s%c%s)", operand1, postfix[i], operand2);
            push(temp);
        }
        else
        {
            sprintf(temp, "%c", postfix[i]);
            push(temp);
        }
    }
    strcpy(infix, stack[top]);
}

int main()
{
    char postfix[MAX_SIZE], infix[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);

    return 0;
}