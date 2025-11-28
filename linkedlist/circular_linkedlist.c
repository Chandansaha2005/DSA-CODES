// circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
} *head;
void create(int);
void display();
void deleteatbeg();
void deleteatend();
void deleteatany(int);
void insertatbeg();
void insertatend();
void insertatany();
void search();
void main()
{
  int n, choice, data;
  while (1)
  {
    printf("\n*MENU*\n");
    printf("1.Create\n2.Display\n3.Deleteatbeg\n4.Deleteatend\n5.Deleteatany\n6.insertatbeg\n7.insertatend\n8.insertatany\n9.search\n10.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice); // 1 2
    switch (choice)
    {
    case 1:
      printf("Enter the number of nodes you want to create:");
      scanf("%d", &n); // n=3
      create(n);       // calling
      break;
    case 2:
      display();
      break;
    case 3:
      deleteatbeg();
      break;
    case 4:
      deleteatend();
      break;
    case 5:
      deleteatany(n);
      break;
    case 6:
      insertatbeg();
      break;
    case 7:
      insertatend();
      break;
    case 8:
      insertatany(); // 5
      break;
    case 9:
      search();
      break;
    case 10:
      exit(0);

    default:
      printf("Wrong choice!!!");
    }
  }
}
void create(int n) // n=3
{
  struct node *newnode, *temp;
  int i, x;
  head = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data you want to insert:");
  scanf("%d", &x);  // 10
  if (head == NULL) // 100==NULL
    printf("Unable to allocate memory.");
  else
  {
    head->data = x;    // 100->data=10
    head->next = head; // 100->next=NULL
    temp = head;       // temp=100
  }
  for (i = 2; i <= n; i++) // i=2;4<=3;i++
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert:");
    scanf("%d", &x);      // x=73
    newnode->data = x;    // 132->data=73
    newnode->next = head; // 132->next=NULL
    temp->next = newnode; // 116->next=132
    temp = newnode;       // temp=132
  }
  display();
}
int c = 0;
void display()
{
  c = 0;
  struct node *temp1 = head; //*temp1=100
  if (head == NULL)          // 100==NULL
  {
    printf("List is empty");
    return;
  }
  else
  {
    printf("Data in the list:\n");
    do
    {
      c++; // c=3
      printf("data=%d and address=%u\n", temp1->data, temp1);
      temp1 = temp1->next; // temp1=100
    } while (temp1 != head); // circular  100!=100
  }
  printf("The number of nodes are:%d", c); // 3
}
void deleteatbeg()
{
  struct node *q = head, *end = head;
  if (end->next == end)
  {
    head = NULL;
    free(end);
  }
  else
  {
    while (end->next != head)
    {
      end = end->next;
    }
    head = q->next;
    free(q);
    end->next = head;
  }
}
void deleteatend()
{
  struct node *q = head, *end = head;
  if (end->next == end)
  {
    head = NULL;
    free(end);
  }
  else
    while (end->next != head)
    {
      q = end;
      end = end->next;
    }
  free(end);
  q->next = head;
}
void deleteatany(int n) {
    struct node *q = head, *end = head, *s;
    int p, i;

    // Ask user for the position to delete
    printf("Enter the position to delete:");
    scanf("%d", &p);

    // Validate the position
    if (p < 1 || p > n) {
        printf("Invalid position! Please enter a position between 1 and %d.\n", n);
        return;
    }

    // Deletion at the beginning
    if (p == 1) {
        deleteatbeg();
        return;
    }

    // Deletion at the end
    if (p == n) {
        deleteatend();
        return;
    }

    // Deletion at any other position
    for (i = 1; i < p; i++) {
        q = end;
        end = end->next;
    }
    s = end->next; // Next node after the one to be deleted
    q->next = s;   // Update the link to skip the deleted node
    free(end);     // Free the memory of the deleted node
    printf("Node deleted at position %d.\n", p);
}
void insertatbeg()
{
  struct node *newnode1, *end = head; // end=100
  int x;
  printf("Enter the data");
  scanf("%d", &x); // x=40
  do
  {
    end = end->next; // end=132
  } while (end->next != head); // 100!=100
  newnode1 = (struct node *)malloc(sizeof(struct node));
  newnode1->data = x;
  newnode1->next = head;
  end->next = newnode1; // 132->next=148
  head = newnode1;      // head=148
  display();
}
void insertatend()
{
  struct node *q, *newnode2, *inend = head; // inend=148
  int x;
  printf("Enter the data");
  scanf("%d", &x); // x=50
  do
  {
    inend = inend->next; // inend=132
  } while (inend->next != head); // 148!=148
  newnode2 = (struct node *)malloc(sizeof(struct node));
  newnode2->data = x;
  newnode2->next = head;
  inend->next = newnode2; // 132->next= 164
  display();
}
void insertatany() // s=5
{
  struct node *newnode3, *temp2 = head, *q;
  int i, n, x;
  printf("Enter the position you want to insert:");
  scanf("%d", &n); // n=3
  if (n == 1)
    insertatbeg();
  else if (n == c + 1)
    insertatend();
  else if (n > c + 1)
    return;
  else
  {
    for (i = 1; i < n; i++) // i=1;1<=3;i++
    {
      q = temp2;           // q=148
      temp2 = temp2->next; // temp2=100
    }
    newnode3 = (struct node *)malloc(sizeof(struct node));
    printf("Enter your data:");
    scanf("%d", &x);
    newnode3->data = x;
    newnode3->next = temp2;
    q->next = newnode3;
  }
}
void search()
{
  int ser, f = 0;
  struct node *temp, *q;
  printf("\nenter the no to be search:");
  scanf("%d", &ser);

  if (head == NULL)
  {
    printf("unable to found!!!No node in the linked list.");
  }
  else
  {
    temp = head;
    do
    {
      if (temp->data == ser)
      {
        f = 1;
        break;
      }
      temp = temp->next;
    } while (temp->next != head);
    //	printf("search not found\n");
  }
  if (f != 1)
    printf("search not found");
  else
    printf("search found");
}
