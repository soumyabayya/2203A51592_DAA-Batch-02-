#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char product_name[50];
    float product_price;
} Product;
void insertionSort(Product *arr, int n, int ascending) {
    int i, j;
    Product key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && ((ascending && arr[j].product_price > key.product_price) || (!ascending && arr[j].product_price < key.product_price))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void displayProducts(Product *arr, int n) {
	int i;
    printf("Product List (sorted by price):\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s Price: %.2f\n", arr[i].product_name, arr[i].product_price);
    }
}
int main() {
    int n;
    int i;
    int ascending;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    Product *products = (Product *)malloc(n * sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter the name of product %d: ", i + 1);
        scanf(" %[^\n]", products[i].product_name); 
        printf("Enter the price of product %d: ", i + 1);
        scanf("%f", &products[i].product_price);
    }
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &ascending);
    insertionSort(products, n, ascending);
    printf("\nAfter sorting:\n");
    displayProducts(products, n);
    free(products);
    return 0;
}
