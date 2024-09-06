#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MANAGERS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char city[MAX_NAME_LENGTH];
    float salary;
} Manager;

typedef struct {
    Manager list[MAX_MANAGERS];
    int count;
} Trade;

void add_manager(Trade *trade, Manager manager) {
    if (trade->count < MAX_MANAGERS) {
        trade->list[trade->count++] = manager;
    }
}

void read_managers(Trade *trade, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Не удалось открыть файл");
        return;
    }

    while (!feof(file)) {
        Manager m;
        fscanf(file, "%d;%[^;];%[^;];%f", &m.id, m.name, m.city, &m.salary);
        add_manager(trade, m);
    }
    fclose(file);
}

void print_kovrov_managers(Trade *trade) {
    printf("Ковровские менеджеры:\n");
    for (int i = 0; i < trade->count; i++) {
        if (strcmp(trade->list[i].city, "КОВРОВ") == 0) {
            printf("%d %s %s %.2f", trade->list[i].id, trade->list[i].name, trade->list[i].city, trade->list[i].salary);
        }
    }
}

int main() {
    Trade trade = { .count = 0 };
    read_managers(&trade, "manager.txt");
    print_kovrov_managers(&trade);
    return 0;
}
