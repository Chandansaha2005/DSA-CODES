// wap to sort the data in quick sort algo
#include <stdio.h>
void swap(int *a, int *b) //*a=&arr[4]   *b=&arr[5]
{
    int t = *a; // t=10
    *a = *b;    //*a=9
    *b = t;     //*b=10
}
int partition(int arr[], int low, int high) //{1, 5, 7, 8, 10, 9},4,5
{
    int pivot = arr[high], i = (low - 1), j; // pivot=8
    for (j = low; j <= high - 1; j++)        // j=4 4<=4 j++
        if (arr[j] < pivot)                  // 10<8
            swap(&arr[++i], &arr[j]);        // calling &arr[0] ,&arr[1]
    swap(&arr[i + 1], &arr[high]);           // i=4 calling &arr[4],&arr[5]
    return (i + 1);                          // i=5
}
void quickSort(int arr[], int low, int high) // arr[]={1, 5, 7, 8, 10, 9},low=4,high=5
{
    if (low < high) // 4<5
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void main()
{
    int n, i;
    printf("Enter the Range = ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d No. = ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1); // calling {10, 7, 8, 9, 1, 5},0,5
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}