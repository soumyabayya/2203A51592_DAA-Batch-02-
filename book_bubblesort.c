#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char title[100];
    char author[100];
    int publicationYear;
    float price;
} Book;
void swap(Book *a, Book *b) {
    Book temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(Book *books, int n, int ascending) {
	int i,j;
    for ( i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((ascending && books[j].price > books[j+1].price) || 
                (!ascending && books[j].price < books[j+1].price)) {
                swap(&books[j], &books[j+1]);
            }
        }
    }
}
void displayBooks(Book *books, int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication Year: %d\n", books[i].publicationYear);
        printf("Price: $%.2f\n\n", books[i].price);
    }
}
int main() {
    int n,i;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", books[i].title);
        printf("Author: ");
        scanf(" %[^\n]", books[i].author);
        printf("Publication Year: ");
        scanf("%d", &books[i].publicationYear);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }
    int ascending;
    printf("Sort by price in 1 for ascending order, 0 for descending order: ");
    scanf("%d", &ascending);
    bubbleSort(books, n, ascending);
    printf("\nBooks sorted by price:\n\n");
    displayBooks(books, n);
    free(books);
    return 0;
}
