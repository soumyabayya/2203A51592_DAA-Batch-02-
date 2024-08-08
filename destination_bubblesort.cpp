#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char id[20];
    char destination[100];
    float weight;
} Package;
void swap(Package *a, Package *b) {
    Package temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(Package *packages, int n, int ascending) {
	int i,j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((ascending && packages[j].weight > packages[j+1].weight) || 
                (!ascending && packages[j].weight < packages[j+1].weight)) {
                swap(&packages[j], &packages[j+1]);
            }
        }
    }
}
void displayPackages(Package *packages, int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("Package ID: %s\n", packages[i].id);
        printf("Destination: %s\n", packages[i].destination);
        printf("Weight: %.2f kg\n\n", packages[i].weight);
    }
}
int main() {
    int n,i;
    printf("Enter the number of packages: ");
    scanf("%d", &n);
    Package *packages = (Package *)malloc(n * sizeof(Package));
    if (packages == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter details for package %d:\n", i + 1);
        printf("Package ID: ");
        scanf(" %[^\n]", packages[i].id);
        printf("Destination: ");
        scanf(" %[^\n]", packages[i].destination);
        printf("Weight (kg): ");
        scanf("%f", &packages[i].weight);
    }
    int ascending;
    printf("Sort by weight in 1 for ascending order , 0 for descending order: ");
    scanf("%d", &ascending);
    bubbleSort(packages, n, ascending);
    printf("\nPackages sorted by weight:\n\n");
    displayPackages(packages, n);
    free(packages);
    return 0;
}
