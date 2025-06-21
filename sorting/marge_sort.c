#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];        /* create temp arrays */
    for (i = 0; i < n1; i++) /* Copy data to temp arrays L[] and R[] */
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    for (i = j = 0, k = l; i < n1 && j < n2; k++) /* Merge the temp arrays back into arr[l..r]*/
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
    while (i < n1) /* Copy the remaining elements of L[], if there are any */
        arr[k++] = L[i++];
    while (j < n2) /* Copy the remaining elements of R[], if there are any */
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) /* l is for left index and r is right index of the sub-array of arr to be sorted */
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}
void main()
{
    int arr[100], n, i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    printf("\nEnter the %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("*Given array is ******** \n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\n**Sorted array is ******\n");
    printArray(arr, n);
}