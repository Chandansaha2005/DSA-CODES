#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 10
void infixtoprefix(char infix[20], char prefix[20]);
void reverse(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);
int top = -1;
char stack[MAX];
char temp[100];
int main()
{
    char infix[10], prefix[10];
    printf("Enter infix operation: ");
    gets(infix);
    infixtoprefix(infix, prefix); // CALLING
    reverse(prefix);              // calling
    puts(temp);
    getch();
    return 0;
}
//--------------------------------------------------------
void infixtoprefix(char infix[], char prefix[])
{
    int i, j = 0;
    char symbol;
    stack[++top] = '#';
    reverse(infix);                    // CALLING
    for (i = 0; i < strlen(temp); i++) // i=0 7<7  i++
    {
        symbol = temp[i];            // symbol='A'
        if (isOperator(symbol) == 0) // calling
        {
            prefix[j] = symbol;
            j++; // 6
        }
        else
        {
            if (symbol == ')')
            {
                push(symbol);
            }
            else if (symbol == '(')
            {
                while (stack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
                if (prcd(stack[top]) < prcd(symbol)) // 4<=2
                {
                    push(symbol);
                }
                else
                {
                    while (prcd(stack[top]) >= prcd(symbol)) // 1>=2
                    {
                        prefix[j] = pop();
                        j++; // 5
                    }
                    push(symbol);
                }
                // end for else
            }
        }
        // end for else
    }
    // end for for
    while (stack[top] != '#') //   '#' != '#'
    {
        prefix[j] = pop(); // CALLING
        j++;               // 7
    }
    prefix[j] = '\0';
}
////--------------------------------------------------------
void reverse(char array[30]) // for reverse of the given expression
{
    int i, j;
    for (i = strlen(array) - 1, j = 0; (i + 1) != 0; --i, ++j) // i=6,j=0; (-1+1)!=0 ;i=-1,j=7
    {
        temp[j] = array[i];
    }
    temp[j] = '\0';
    strcpy(array, temp);
    // return array;
}
//--------------------------------
char pop()
{
    char a;
    a = stack[top]; // a='+'
    top--;          // 0
    return a;
}
//----------------------------------
void push(char symbol) //'+'
{
    top++; // 1
    stack[top] = symbol;
}
//------------------------------------------
int prcd(char symbol) // returns the value that helps in the precedence
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '$':
    case '^':
        return 6;
        break;
    case '#':
    case '(':
    case ')':
        return 1;
        break;
    }
}
//-------------------------------------------------
int isOperator(char symbol) //'*'
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
    case '&':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
    }
}