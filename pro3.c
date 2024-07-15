#include <stdio.h>
#include <stdlib.h>

struct City {
    char *name;
    int population;
};

void free_memory(struct City **cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);
}

int main() {
    FILE *file;
    char line[1000]; // Assuming a maximum line length of 1000 characters

    file = fopen("test.txt", "r"); // Replace "example.txt" with your file name

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int num_cities;
    fscanf(file, "%d", &num_cities);

    struct City **cities = (struct City **)malloc(num_cities * sizeof(struct City *));
    if (!cities) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < num_cities; i++) {
        cities[i] = (struct City *)malloc(sizeof(struct City));
        if (!cities[i]) {
            perror("Error allocating memory");
            free_memory(cities, i);
            fclose(file);
            return 1;
        }
        cities[i]->name = (char *)malloc(100 * sizeof(char)); // Assuming max city name length of 100 characters
        if (!cities[i]->name) {
            perror("Error allocating memory");
            free_memory(cities, i + 1);
            fclose(file);
            return 1;
        }

        fscanf(file, "%s %d", cities[i]->name, &cities[i]->population);
    }

    fclose(file);

    // Use the array of structures here
    // For example, print the data
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s, Population: %d\n", cities[i]->name, cities[i]->population);
    }

    // Don't forget to free the allocated memory
    free_memory(cities, num_cities);

    return 0;
}

