// Heap Sort
#include <stdio.h>
void heapify(int a[], int i, int n)
{
    int j;
    for (j = 2 * i + 1; j < n; j = 2 * i + 1)
    {
        int temp, bci = j;
        if (j + 1 < n)
            if (a[j] < a[j + 1])
                bci = j + 1;
        if (a[i] < a[bci])
        {
            temp = a[i];
            a[i] = a[bci];
            a[bci] = temp;
        }
        else
            break;
        i = bci;
    }
}

void BuildMaxHeap(int a[], int n)
{
    int i, j;
    for (i = n / 2; i >= 0; i--)
    {
        heapify(a, i, n);
    }
}
void sort(int a[], int n)
{
    int temp, i;
    BuildMaxHeap(a, n);
    for (i = 1; i < n; i++)
    {
        temp = a[0];
        a[0] = a[n - i];
        a[n - i] = temp;
        heapify(a, 0, n - i);
    }
}
void main()
{
    int n, i;
    printf("Enter the Range:");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number=");
        scanf("%d", &a[i]);
    }
    sort(a, n);
    printf("\nHeap Sort list:");
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
}