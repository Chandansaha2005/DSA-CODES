#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int dq[MAX];
int left = -1, right = -1;

void insert_right();
void insert_left();
void delete_left();
void delete_right();
void display();

int main()
{
    int c;
    do
    {
        printf("\n1.Insert at right\n2.Insert at left\n3.Delete from left\n4.Delete from right\n5.Quit\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            delete_right();
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (c != 5);
    return 0;
}

void insert_right()
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (left == -1) // queue empty
        left = right = 0;
    else
    {
        right = (right + 1) % MAX;
    }
    printf("Input the element : ");
    scanf("%d", &dq[right]);
    display();
}

void insert_left()
{
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (left == -1) // queue empty
        left = right = 0;
    else
    {
        left = (left - 1 + MAX) % MAX;
    }
    printf("Input the element : ");
    scanf("%d", &dq[left]);
    display();
}

void delete_left()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Element : %d\n", dq[left]);
    if (left == right) // only one element
        left = right = -1;
    else
        left = (left + 1) % MAX;
    display();
}

void delete_right()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Element : %d\n", dq[right]);
    if (left == right) // only one element
        left = right = -1;
    else
        right = (right - 1 + MAX) % MAX;
    display();
}

void display()
{
    if (left == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements : ");
    int i = left;
    while (1)
    {
        printf("%d ", dq[i]);
        if (i == right)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
