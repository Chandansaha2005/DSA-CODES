//WAP to implement circular queue by using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int cqueue[MAX], f = -1, r = -1;
void insert();
void del();
void display();
void main()
{
    int c;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Quit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1 :
            insert();//calling
            break;
        case 2 :
            del();//calling
            break;
        case 3:
            exit(0);           
        default:
            printf("Wrong choice\n");
        }
    }
    while(c!=4);
}
void insert()//x=40
{
    if((f == 0 && r == MAX-1) || (f == r+1))
    {
        printf("\nQueue Overflow \n");
        return;
    }
    if (f == -1)  /*If queue is empty */
        f = r = 0;
    else
    {
        if(r == MAX-1)	/*r is at last position of queue */
            r = 0;
        else
            r++;//2
    }
    printf("Enter the No. = ");
    scanf("%d", &cqueue[r]);//cqueue[1]=20
    display();
}
void del()
{
    if (f == -1)
    {
        printf("\nQueue Underflow\n");
        return ;
    }
    printf("Deleted : %d\n",cqueue[f]);
    if(f == r) /* queue has only one element */ //circular
        f = r = -1;
    else
    {	
        if(f == MAX-1)//circular queue
            f = 0;//circular queue
        else
            f = f+1;//2
    }
    display();
}
void display()//func. definition
{
	int i;
    if (f == - 1)
    {
        printf("\nQueue is empty \n");
        return;
    }
    printf("\nQueue is : \n");
    for(i=f;;i=(i+1)%MAX)
    {
        printf("%d ",cqueue[i]);
        if(i==r)
            break;
    }
}
