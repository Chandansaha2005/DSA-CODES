#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node *next;
};
struct Node *head;
int count = 0 ; 
void createNode(int n){
    struct Node *newNode , *temp ;
    head=NULL;
    for(int i = 0 ; i < n ; i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the Element = ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
    }

}
void main (){
    createNode(5);
}