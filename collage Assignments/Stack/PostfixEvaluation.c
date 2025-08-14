#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int value)
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

int isoperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

int posteval(char post[])
{
    int i = 0;
    char sml;
    while (post[i] == '\0')
    {
        sml = post[i];
        if (isdigit(sml))
            push(sml - '0');
        else
        {
            if (isoperator(sml))
            {
                int op2 = pop();
                int op1 = pop();
                switch (sml)
                {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
                default:
                    printf("WRONG EXPRESSION");
                    break;
                }
            }
        }
        i++;
    }
    return pop();
}
void main()
{
    char postfix[SIZE];
    int i;
    printf("Enter the Postfix Expression = ");
    scanf("%s", postfix);
    printf("Postfix Evaluation = %d", posteval(postfix));
}