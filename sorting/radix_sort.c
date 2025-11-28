// RADIX SORT
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) // TECHNOLOGIAA
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void radixSortWithBubbleSort(int arr[], int n)
{
    int max_val = arr[0], exp;
    for (int i = 1; i < n; ++i) // to get the maximum value
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    for (exp = 1; max_val / exp > 0; exp *= 10)
    {
        int radixArray[10][n], count[10] = {0}, index = 0;
        for (int i = 0; i < n; ++i)
        {
            int radixIndex = (arr[i] / exp) % 10;
            radixArray[radixIndex][count[radixIndex]++] = arr[i];
        }
        for (int i = 0; i < 10; ++i)
        {
            if (count[i] >= 1)
                bubbleSort(radixArray[i], count[i]);
        }
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < count[i]; ++j)
                arr[index++] = radixArray[i][j];
        }
    }
}

void main()
{
    int n;
    printf("Enter the range : ");
    scanf("%d", &n);
    int myArray[n], i;
    printf("Enter the array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &myArray[i]);
    printf("Original array : ");
    for (int i = 0; i < n; ++i)
        printf("%d ", myArray[i]);
    printf("\n");

    radixSortWithBubbleSort(myArray, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", myArray[i]);
    printf("\n");
}