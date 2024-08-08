#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n, int ascending) {
	int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n, order,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &order);
    printf("Original array: \n");
    printArray(arr, n);
    insertionSort(arr, n, order);
    printf("Sorted array: \n");
    printArray(arr, n);
    free(arr);
    return 0;
}
