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
    (f < 0) ? printf("NOT found\n") : printf("Found at position = %d\n", f + 1);
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
    int arr[100], n, i, c = 0;
    printf("Enter the number of elements = ");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    do
    {
        int val, pos;
        printf("\nEnter 1 For Insert");
        printf("\nEnter 2 For Delete");
        printf("\nEnter 3 For Replace");
        printf("\nEnter 4 For Search");
        printf("\nEnter 5 For Display");
        printf("\nEnter 6 For Exit");
        printf("\nEnter Your Choice = ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter The Value To Insert = ");
            scanf("%d", &val);
            printf("\nEnter 1 For Insert At Beg ");
            printf("\nEnter 2 For Insert At End");
            printf("\nEnter 3 For Insert At Specific");
            printf("\nEnter Your Choice = ");
            scanf("%d", &pos);
            switch (pos)
            {
            case 1:
                insert(arr, &n, val, 1);
                break;
            case 2:
                insert(arr, &n, val, n);
                break;
            case 3:
                printf("Enter The Position To Insert = ");
                scanf("%d", &pos);
                insert(arr, &n, val, pos);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("\nEnter 1 For Delete At Beg ");
            printf("\nEnter 2 For Delete At End");
            printf("\nEnter 3 For Delete At Specific");
            printf("\nEnter Your Choice = ");
            scanf("%d", &pos);
            switch (pos)
            {
            case 1:
                del(arr, &n, 1);
                break;
            case 2:
                del(arr, &n, n);
                break;
            case 3:
                printf("Enter The Position To Delete = ");
                scanf("%d", &pos);
                del(arr, &n, pos);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("Enter The Position To Replace = ");
            scanf("%d", &pos);
            printf("Enter The Number = ");
            scanf("%d", &val);
            replace(arr, n, val, pos);
            break;
        case 4:
            printf("Enter The Number to Search = ");
            scanf("%d", &val);
            search(arr, n, val);
            break;
        case 5:
            display(arr, n);
            break;
        default:
            exit(0);
        }
    } while (c < 6);
}
