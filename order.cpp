#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int order_id;
    int manager_id;
    int client_id;
    char order_date[20];
    float amount;
} Order;

void print_order(Order order) {
    printf("%d. %d %d %s %.2f\n", order.order_id, order.manager_id, order.client_id, order.order_date, order.amount);
}

int compare_orders(const void *a, const void *b) {
    Order *orderA = (Order *)a;
    Order *orderB = (Order *)b;
    if (orderA->amount < orderB->amount) return 1;
    if (orderA->amount > orderB->amount) return -1;
    return 0;
}

int main() {
    FILE *orders_f = fopen("order.txt", "r");
    if (!orders_f) {
        perror("Failed to open file");
        return 1;
    }

    Order orders[100];
    int count = 0;

    char line[256];
    while (fgets(line, sizeof(line), orders_f)) {
        if (sscanf(line, "%d;%d;%d;%19[^;];%f",
                    &orders[count].order_id,
                    &orders[count].manager_id,
                    &orders[count].client_id,
                    orders[count].order_date,
                    &orders[count].amount) == 5) {
            count++;
        }
    }

    fclose(orders_f);

    qsort(orders, count, sizeof(Order), compare_orders);

    FILE *orders_sorted_f = fopen("orders_sorted.txt", "w");
    if (!orders_sorted_f) {
        perror("Failed to open output file");
        return 1;
    }

    fprintf(orders_sorted_f, "order_id, manager_id, client_id, order_date, amount\n");
    for (int i = 0; i < count; i++) {
        fprintf(orders_sorted_f, "%d. %d %d %s %.2f\n",
                orders[i].order_id,
                orders[i].manager_id,
                orders[i].client_id,
                orders[i].order_date,
                orders[i].amount);
    }

    fclose(orders_sorted_f);

    printf("orders done\n");
    return 0;
}
