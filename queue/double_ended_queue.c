//DEQUEUE(Double ended queue)
#include<stdio.h>
#define MAX 5
void insert_right();
void insert_left();
void delete_left();
void delete_right();
void display();
int dq[MAX],left = -1, right = -1;
void main()
{	
    int c;
    do
    {	
        printf("1.Insert at right\n2.Insert at left\n3.Delete from left\n4.Delete from right\n5.Quit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
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
    }
    while(c!=5);
}
void insert_right()
{
    if((left == 0 && right == MAX-1) || (left == right+1))
    {	
        printf("Queue Overflow\n");
        return;
    }
    if (left == -1)  /* if queue is initially empty */
    	left = right = 0;
    else 
        if(right++ == MAX-1)  /*right is at last position of queue */
            right = 0;
    printf("Input the element : ");
    scanf("%d", &dq[right]);
    display();
}
void insert_left()
{	
    if((left == 0 && right == MAX-1) || (left == right+1))
    {	
        printf("Queue Overflow \n");
        return;	
    }
    if (left == -1)//If queue is initially empty/
    	left = right = 0;
    else
        if(left-- == 0)
            left=MAX-1;
    printf("Input the element : ");
    scanf("%d", &dq[left]);	 
    display();
}
void delete_left()
{	
    if (left == -1)
    {	
        printf("Queue Underflow\n");
        return ;	
    }
    printf("Deleted Element : %d\n",dq[left]);
    if(left == right) /*Queue has only one element */
        left = right = -1;
    else
        if(left++ == MAX-1)
            left = 0;
    display();
}
void delete_right()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return ;	 
    }
    printf("Deleted Element : %d\n",dq[right]);
    if(left == right) //queue has only one element/
    	left = right = -1;
    else
        if(right-- == 0)
            right=MAX-1;	
    display();
}
void display()
{	
    int f = left,r = right;
    if(left == -1)
    {	
        printf("Queue is empty\n");
        return;	 
    }
    printf("Queue elements :\n");
    if( f <= r )
        while(f <= r)
        	printf("%d ",dq[f++]);	
    else
    {
        while(f <= MAX-1)
            printf("%d ",dq[f++]);
        for(f = 0;f <= r;)
            printf("%d ",dq[f++]);
    }
    printf("\n");
}

