#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SIZE 100
int stack[SIZE], top = -1;

void push(int value){
    stack[++top] = value;
}

int pop(){
    if (top == -1) return -1;
    else return stack[top--];
}

int isoperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

int posteval(char post[])
{
    int i = 0;
    char sml;
    while (post[i] != '\0')
    {
        sml = post[i];
        if (isdigit(sml)) push(sml - '0');
        else if (isoperator(sml)){
            int op2 = pop(),op1 = pop();
            if(sml=='+') push(op1 + op2);
            if(sml=='-') push(op1 - op2);
            if(sml=='*') push(op1 * op2);
            if(sml=='/') push(op1 / op2);
            if(sml=='^') push(pow(op1, op2));
        }
        else{
            printf("WRONG EXPRESSION");
            exit(0);
        }i++;
    }return pop();
}

void main(){
    char postfix[SIZE];
    printf("Enter the Postfix Expression = ");
    scanf(" %s", postfix);
    printf("Postfix Evaluation = %d", posteval(postfix));
}