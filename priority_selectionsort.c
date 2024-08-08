#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int order_id;
    char customer_name[50];
    double order_amount;
    int priority;
} Order;
void selection_sort(Order* orders, int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++) {
            if (orders[j].priority < orders[min_index].priority) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Order temp = orders[i];
            orders[i] = orders[min_index];
            orders[min_index] = temp;
        }
    }
}
void print_orders(Order* orders, int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("Priority: %d,Order ID: %d, Customer Name: %s, Order Amount: %.2f\n",
                orders[i].priority,orders[i].order_id, orders[i].customer_name, orders[i].order_amount);
    }
}
int main() {
    int n,i;
    printf("Enter the number of orders: ");
    scanf("%d", &n);
    Order* orders = (Order*)malloc(n * sizeof(Order));
    if (orders == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter details for order %d\n", i + 1);
        printf("Order ID: ");
        scanf("%d", &orders[i].order_id);
        printf("Customer Name: ");
        scanf("%s", orders[i].customer_name);
        printf("Order Amount: ");
        scanf("%lf", &orders[i].order_amount);
        printf("Priority: ");
        scanf("%d", &orders[i].priority);
    }
    selection_sort(orders, n);
    print_orders(orders, n);
    free(orders);
    return 0;
}
