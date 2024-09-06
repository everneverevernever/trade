/* Задача Торговля. Этап 1. */
#include <stdio.h>
struct Manager {
    int manager_id;
    const char *name;
    const char *city;
    double comm;
};

int main() {
    Manager man = {1, "Vasya", "Moskva", 0.25};
    printf("id=%d, name=%s, city=%s, comm=%.2f\n", man.manager_id, man.name, man.city, man.comm);
    
    return 0;
}
