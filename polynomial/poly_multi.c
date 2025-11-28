#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    // Define useful field of Node
    int data;
    int power;
    struct Node * next;
}Node;
Node * getNode(int data, int power)
{
    // Create dynamic memory of Node
    Node * ref = (Node * ) malloc(sizeof(Node));
    if (ref == NULL)
    {
        // Failed to create memory 
        return NULL;
    }
    ref->data = data;
    ref->power = power;
    ref->next = NULL;
    return ref;
}
// Update node value
void updateRecord(Node * ref, int data, int power)
{
    ref->data = data;
    ref->power = power;
}
typedef struct MultiplyPolynomial
{
    // Define useful field of MultiplyPolynomial
    struct Node * head;
}MultiplyPolynomial;
MultiplyPolynomial * getMultiplyPolynomial()
{
    // Create dynamic memory of MultiplyPolynomial
    MultiplyPolynomial * ref = (MultiplyPolynomial * )
                    malloc(sizeof(MultiplyPolynomial));
    if (ref == NULL)
    {
        // Failed to create memory 
        return NULL;
    }
    ref->head = NULL;
    return ref;
}
// Insert Node element
void insert(MultiplyPolynomial * ref, int data, int power)
{
    if (ref->head == NULL)
    {
        // Add first node
        ref->head = getNode(data, power);
    }
    else
    {
        Node * node = NULL;
        Node * temp = ref->head;
        Node * location = NULL;
        // Find the valid new node location
        while (temp != NULL && temp->power >= power)
        {
            location = temp;
            temp = temp->next;
        }
        if (location != NULL && location->power == power)
        {
            // When polynomial power already exists
            // Then add current add to previous data
            location->data = location->data + data;
        }
        else
        {
            node = getNode(data, power);
            if (location == NULL)
            {
                // When add node in begining
                node->next = ref->head;
                ref->head = node;
            }
            else
            {
                // When adding node in intermediate 
                // location or end location
                node->next = location->next;
                location->next = node;
            }
        }
    }
}
// Perform multiplication of given polynomial
MultiplyPolynomial * multiplyPolynomials(
  MultiplyPolynomial * ref, MultiplyPolynomial * other)
{
    // Define some useful variable
    MultiplyPolynomial * result = getMultiplyPolynomial();
    // Get first node of polynomial
    Node * poly1 = ref->head;
    Node * temp = other->head;
    int power_value = 0;
    int coefficient = 0;
    // Execute loop until when polynomial are exist
    while (poly1 != NULL)
    {
        temp = other->head;
        while (temp != NULL)
        {
            // Get result info
            power_value = poly1->power + temp->power;
            coefficient = poly1->data * temp->data;
            insert(result, coefficient, power_value);
            // Visit to next node
            temp = temp->next;
        }
        // Visit to next node
        poly1 = poly1->next;
    }
    // return first node
    return result;
}
void display(MultiplyPolynomial * ref)
{
    if (ref->head == NULL)
    {
        printf("Empty Polynomial ");
    }
    printf(" ");
    Node * temp = ref->head;
    while (temp != NULL)
    {
        if (temp != ref->head)
        {
            printf(" + %d", temp->data);
        }
        else
        {
            printf("%d",temp->data);
        }
        if (temp->power != 0)
        {
            printf("x^%d", temp->power);
        }
        // Visit to next node
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int f=1,c,p,i=1;
	MultiplyPolynomial * a = getMultiplyPolynomial();
	MultiplyPolynomial * b = getMultiplyPolynomial();
	printf("Enter the elements of 1st polynomial :");
	while(f==1)
	{
		printf("\nEnter Coefficient(%d): ",i);
		scanf("%d",&c);
		printf("Enter Power(%d): ",i++);
		scanf("%d",&p);
		insert(a, c, p);
		printf("Enter Next Element (Yes = 1 / No = 0) : ");
		scanf("%d",&f);
	}
	f=1;
	i=1;
	printf("\nEnter the elements of 2nd polynomial :");
	while(f==1)
	{
		printf("\nEnter Coefficient(%d): ",i);
		scanf("%d",&c);
		printf("Enter Power(%d): ",i++);
		scanf("%d",&p);
		insert(b, c, p);
		printf("Enter Next Element (Yes = 1 / No = 0) : ");
		scanf("%d",&f);
	}
	printf("\n Polynomial A:\n");
	display(a);
	printf(" Polynomial B:\n");
	display(b);
	MultiplyPolynomial * result = multiplyPolynomials(a, b);
	// Display calculated result
	printf(" Result:\n");
	display(result);
}