#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int product_id;
    char name[50];
    double price;
} Product;
void insertion_sort(Product* products, int n) {
	int i,j;
    for (i = 1; i < n; i++) {
        Product key = products[i];
        j = i - 1;
        while (j >= 0 && products[j].product_id > key.product_id) {
            products[j + 1] = products[j];
            j = j - 1;
        }
        products[j + 1] = key;
    }
}
void print_inventory(Product* products, int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("Product ID: %d, Name: %s, Price: %.2f\n", products[i].product_id, products[i].name, products[i].price);
    }
}
int main() {
    int n,i;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    Product* inventory = (Product*)malloc(n * sizeof(Product));
    if (inventory == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter details for product %d\n", i + 1);
        printf("Product ID: ");
        scanf("%d", &inventory[i].product_id);
        printf("Name: ");
        scanf("%s", inventory[i].name);
        printf("Price: ");
        scanf("%lf", &inventory[i].price);
    }
    insertion_sort(inventory, n);
    print_inventory(inventory, n);
    free(inventory);
    return 0;
}
