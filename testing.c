#include <stdio.h>
#include <string.h>

struct City {
    char name[100];
    double area;
    int population;
};

void searchCity(struct City *cities, int num_cities, char *target) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, target) == 0) {
            printf("City found - Name: %s, Area: %lf, Population: %d\n", cities[i].name, cities[i].area, cities[i].population);
            return;
        }
    }
    printf("City not found.\n");
}

int main() {
    struct City cities[4] = {
        {"Bogura", 400983.0, 200000},
        {"Brahmanbaria", 193814.0, 100000},
        {"Chuadanga", 128865.0, 50000},
        {"Cox's Bazar", 223522.0, 300000}
    };

    // Print city information
    for (int i = 0; i < 4; i++) {
        printf("City: %s, Area: %lf, Population: %d\n", cities[i].name, cities[i].area, cities[i].population);
    }

    // Search for a specific city
    char target_city[100];
    printf("Enter the name of the city to search for: ");
    scanf("%s", target_city);

    searchCity(cities, 4, target_city);

    return 0;
}

void searchCity(struct City *cities, int num_cities, char *target) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, target) == 0) {
            printf("City found - Name: %s, Area: %lf, Population: %d\n", cities[i].name, cities[i].area, cities[i].population);
            return;
        }
    }
    printf("City not found.\n");
}


    char target_city[100];
    printf("Enter the name of the city to search: ");
    scanf("%s",target_city);
    searchCity(cities, num_cities, target_city);
