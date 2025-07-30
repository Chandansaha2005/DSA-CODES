#include <stdio.h>
int d, b = -1, binary[100];
void display()
{
    printf("%d in Binary = ", d);
    for (int i = 0; i <= b; i++)
    {
        printf("%d ", binary[i]);
    }
}
void convertBinary(int d)
{
    if (d == 0)
    {
        binary[++b] = 0;
    }
    else
    {
        for (int i = d; i >= 0; i = d / 2)
            binary[++b] = i % 2;
    }
    display();
}
void main()
{
    printf("----DECIMAL TO BINARY----");
    printf("\nEnter the Decimal Number = ");
    scanf("%d", &d);
    convertBinary(d);
}