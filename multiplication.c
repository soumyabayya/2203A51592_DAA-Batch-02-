#include <stdio.h>
int main() {
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns for the first matrix (r1 c1): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for the second matrix (r2 c2): ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Number of columns in first matrix must equal number of rows in second matrix.\n");
        return 1;
    }
    int matrix1[r1][c1], matrix2[r2][c2], result[r1][c2],i,j,k;
    printf("Enter the elements of the first matrix (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix (%dx%d):\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    for ( i = 0; i < r1; i++) {
        for ( j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nThe resultant matrix after multiplication is (%dx%d):\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
