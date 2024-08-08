#include <stdio.h>
#include <stdlib.h>
void selectionSort(int arr[], int n, int ascending) {
	int i,j,extremeIndex;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if ((ascending && arr[j] < arr[extremeIndex]) || 
                (!ascending && arr[j] > arr[extremeIndex])) {
                extremeIndex = j;
            }
        }
        if (extremeIndex != i) {
            int temp = arr[i];
            arr[i] = arr[extremeIndex];
            arr[extremeIndex] = temp;
        }
    }
}
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n,i, order;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &order);
    printf("Original array: \n");
    printArray(arr, n);
    selectionSort(arr, n, order);
    printf("Sorted array: \n");
    printArray(arr, n);
    free(arr);
    return 0;
}
