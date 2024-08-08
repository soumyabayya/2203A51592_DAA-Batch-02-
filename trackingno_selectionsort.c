#include <stdio.h>
#include <string.h>
#define MAX_PACKAGES 100
typedef struct {
    int house_no;
    char street[50];
    char city[50];
    int tracking_number;
} Package;
void swap(Package *a, Package *b) {
    Package temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(Package packages[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (packages[j].tracking_number < packages[min_idx].tracking_number) {
                min_idx = j;
            }
        }
        swap(&packages[i], &packages[min_idx]);
    }
}
void printPackages(Package packages[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("Package %d:\n", i + 1);
        printf("  House No: %d\n", packages[i].house_no);
        printf("  Street: %s\n", packages[i].street);
        printf("  City: %s\n", packages[i].city);
        printf("  Tracking Number: %d\n", packages[i].tracking_number);
    }
}
int main() {
    Package packages[MAX_PACKAGES];
    int n,i;
    printf("Enter the number of packages: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter details for package %d:\n", i + 1);
        printf("  House No: ");
        scanf("%d", &packages[i].house_no);
        printf("  Street: ");
        scanf(" %[^\n]%*c", packages[i].street); 
        printf("  City: ");
        scanf(" %[^\n]%*c", packages[i].city);
        printf("  Tracking Number: ");
        scanf("%d", &packages[i].tracking_number);
    }
    selectionSort(packages, n);
    printf("\nPackages sorted by tracking number:\n");
    printPackages(packages, n);
    return 0;
}
