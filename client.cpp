#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CITY_LENGTH 100


typedef struct {
    int client_id;
    char name[MAX_NAME_LENGTH];
    char city[MAX_CITY_LENGTH];
    int rating;
    int manager_id;
} Client;



int main() {
    Client client = {1, "Vasya", "Moskva", 1, 1};
    printf("client_id=%d, name=%s, city=%s, rating=%d, manager_id=%d", client.client_id, client.name, client.city, client.rating, client.manager_id);

    return 0;
}
