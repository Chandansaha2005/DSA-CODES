// WAP to implement stack using array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void push();               // function declaration
void pop();                // function declaration
void display();            // function declaration//peep()   peek()
int stack[SIZE], top = -1; // variable declaration
int value, choice;
void main()
{
   while (1)
   {
      printf("\n\n***** MENU *****\n");
      printf("1. Push\n2. Pop\n3. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         push(); // func. calling
         break;
      case 2:
         pop(); // func. calling
         break;
      case 3:
         exit(0);
      default:
         printf("\nWrong selection!!! Try again!!!");
      }
   }
}
void push() // func. definition
{
   if (top == SIZE - 1)
   {
      printf("\nStack is Full!!! Insertion is not possible!!!");
      return;
   }
   else
   {
      printf("Enter the No. = ");
      scanf("%d", &value);
      top++;
      stack[top] = value;
      printf("\nInsertion success!!!");
      display();
   }
}
void pop() // func. definition
{
   if (top == -1)
   {
      printf("\nStack is Empty!!! Deletion is not possible!!!");
      return;
   }
   else
   {
      printf("\nDeleted : %d\n", stack[top]);
      top--;
      display();
   }
}
void display() // func. definition
{
   int i;
   if (top == -1)
   {
      printf("Stack is empty \n");
      return;
   }
   else
   {
      printf("Stack is : \n");
      for (i = 0; i <= top; i++)
         printf("%d ", stack[i]);
      printf("\n");
   }
}
