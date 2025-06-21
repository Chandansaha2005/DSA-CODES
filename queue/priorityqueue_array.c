//wap to implement priority queue using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void insert(int);
void del(int);
void check(int);
void display_pqueue();
int pri_que[MAX], f = -1, r = -1;
void main()
{
    int n, ch;
    printf("\n1 - Insert an element into queue\n2 - Delete an element from queue\n3 - Exit");
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: 
                printf("\nEnter value to be inserted : ");
                scanf("%d",&n);//n=15 10
                insert(n);//calling 
                break;
            case 2:
                printf("\nEnter value to delete : ");
                scanf("%d",&n);//n=50
                del(n);//calling 
                break;
            case 3: 
                exit(0);
            default: 
                printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
void insert(int data)
{
    if (r >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((f == -1) && (r == -1))
    {
        f++;
        pri_que[++r] = data;
        return;
    }    
    else
        check(data);//calling 
    r++;//1
    display_pqueue();
}
void check(int data)
{
    int i,j;
    for ( i = 0; i <= r; i++)
    {
        if (data >= pri_que[i])//10>=15
        {
            for ( j = r + 1; j > i; j--)
                pri_que[j] = pri_que[j - 1];
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;//
}
void del(int data)
{
    int i;
    if ((f==-1) && (r==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i = 0; i <= r; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < r; i++)//i=0  0<0 i++
                pri_que[i] = pri_que[i + 1];
            pri_que[i] = 0;
            r--;//-1
            if (r == -1) 
                f = -1;
            return;
        }
    }
    printf("\n%d not found in queue to delete", data);
    display_pqueue();
}
void display_pqueue()
{
    if ((f == -1) && (r == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (int i=f; i<= r; i++)
        printf(" %d ", pri_que[i]);
}
