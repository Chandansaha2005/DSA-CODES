#include <stdio.h>
void radixSort(int a[], int n) {
    int i, j, max = a[0], exp, ri, ra[10][n], c[10];
    for (i = 1; i < n; i++) if (a[i] > max) max = a[i];
    for (exp = 1; max / exp; exp *= 10) {
        for (i = 0; i < 10; i++) c[i] = 0;
        for (i = 0; i < n; i++) {
            ri = (a[i] / exp) % 10;
            ra[ri][c[ri]++] = a[i];
        }
        for (i = j = 0; i < 10; i++)
            for (int k = 0; k < c[i]; k++)
                a[j++] = ra[i][k];
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
void main() {
    int n;
    printf("Enter range: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Original array: ");
    print(a, n);
    radixSort(a, n);
    printf("Sorted array: ");
    print(a, n);
}