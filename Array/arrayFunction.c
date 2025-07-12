#include <stdio.h>
#include <stdlib.h>
void search(int arr[], int n, int val)
{
    int i, f = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            f = i;
        }
    }
    (f < 0) ? printf("\nNOT found\n") : printf("\nFound at position = %d\n", f + 1);
}
void replace(int arr[], int n, int val, int pos)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i == pos - 1)
        {
            arr[i] = val;
            break;
        }
    }
}
void del(int arr[], int *n, int pos)
{
    int i = 0;
    if (pos - 1 > *n || pos - 1 < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        for (i = pos - 1; i < *n; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }
}
void insert(int arr[], int *n, int val, int pos)
{
    int i = 0;
    if (pos - 1 > *n || pos - 1 < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        for (i = *n; i > pos - 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = val;
        (*n)++;
    }
}
void display(int arr[], int n)
{
    printf("Array = ");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void input(int arr[], int n)
{
    printf("Enter the elements = ");
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void main()
{
    int arr[100], n, i;
    printf("Enter the number of elements = ");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    
}
