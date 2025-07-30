#include <stdio.h>
#define SIZE 100
int d, top = -1, stack[SIZE];
void push(int value)
{
    stack[++top] = value;
}
int pop()
{
    int bi = stack[top--];
    return bi;
}
void main()
{
    printf("----DECIMAL TO BINARY----");
    printf("\nEnter the Decimal Number = ");
    scanf("%d", &d);
    for (int i = d; i > 0; i /= 2)
        push(i % 2);
    printf("%d In Binary = ", d);
    int n = top;
    for (int i = 0; i <= n; i++)
    {
        int bi = pop();
        if (bi != -1)
            printf("%d ", bi);
    }
}