//Wap to create/insert a tree from ar array
#include<stdio.h>
#include<conio.h>
struct node 
{
   int data; 	
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;
void insert(int);
struct node* search(int);
int search1(int);
void pre_order_traversal(struct node*);
void post_order_traversal(struct node*);
void in_order_traversal(struct node*);
int main() 
{
   int i,n,x;
   printf("Enter the Range=");
   scanf("%d",&n);//n=5
   int array[n];
   //input 
   for(i=0;i<n;i++)//i=0  0<5
    {
      printf("Enter the No.=");
      scanf("%d",&array[i]);
    }
   //tree insert
   for(i=0;i<n;i++)//i=5  <5
    {
      insert(array[i]);//calling  10  20 30 15 50
    }
    printf("Enter the No. to be Search=");
    scanf("%d",&x);//x=30
 //search 1 process
    if(search1(x)==1)//func. calling
     printf("\nSearch Found");
    else
     printf("\nSearch NOT Found");
//search 2nd process
    printf("Enter the No. to be Search=");
    scanf("%d",&x);//x=30
   struct node *temp = search(x);//calling  x=30  temp=148
   if(temp != NULL)
   {
      printf("\n[%d] Element found. %u", temp->data,temp); //30
      printf("\n");
   }
   else 
   {
      printf("\n[ x ] Element not found (%d).\n", i);
   }
           
   printf("\nPreorder traversal: ");
   pre_order_traversal(root);//calling  root=100
   printf("\nInorder traversal: ");
   inorder_traversal(root); //calling root =100
   printf("\nPost order traversal: ");
   post_order_traversal(root);//calling root=100
   getch();
   return 0;
}
void insert(int data)//data =50
{
   struct node *tempNode ;
   tempNode= (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;
   //if tree is empty
   if(root == NULL)
  {
      root = tempNode;
   } 
   else 
   {
      current = root;//current=100
      parent = NULL;
      while(1) 
      { 
         parent = current;  //parent=100 
         //go to left of the tree
         if(data < parent->data) //50<30
         {
            current = current->leftChild;                
            //insert to the left
            if(current == NULL) 
            {
               parent->leftChild = tempNode;
               return;
            }
         }  //go to right of the tree
         else
         {
            current = current->rightChild;//NULL
            //insert to the right
            if(current == NULL) 
            {
               parent->rightChild = tempNode;//148
               return;
            }
         }
      }            
   }
}
struct node* search(int data) //data=30
{
   struct node *current = root;//current=100
   printf("Visiting elements: ");
   while(current->data != data) //30!=30
   {
      if(current != NULL)
         printf("%d ",current->data);//10 20
      //go to left tree
      if(current->data > data)//20>30 
      {
         current = current->leftChild;
      }
      //else go to right tree
      else
      {                
         current = current->rightChild;//current=148
      }
      //not found
      if(current == NULL) 
      {
         return NULL;
      }
   }
   return current;
}
int search1(int data) //data=60
{
   struct node *current = root;
   printf("Visiting elements: ");
   while(current->data != data) //50!=60
   {
      if(current != NULL)//196!=NULL
         printf("%d ",current->data); //10 20 30 50
      //go to left tree
      if(current->data > data) //50>60
      {
         current = current->leftChild;
      }
      //else go to right tree
      else
      {                
         current = current->rightChild;//current=NULL
      }
      //not found
      if(current == NULL) 
      {
         return 0;
      }
   }
   return 1;
}
void pre_order_traversal(struct node* root)//root=196
{
   if(root != NULL)
   {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);//recursion
      pre_order_traversal(root->rightChild);//recursion
   }
}
void inorder_traversal(struct node* root)//root=NULL
{
   if(root != NULL)
   {
      inorder_traversal(root->leftChild);//calling NULL
      printf("%d ",root->data);          
      inorder_traversal(root->rightChild);//calling  196
   }
}
void post_order_traversal(struct node* root)//root=100
{
   if(root != NULL)
   {
      post_order_traversal(root->leftChild);//null
      post_order_traversal(root->rightChild);//null
      printf("%d ", root->data);
   }
 }