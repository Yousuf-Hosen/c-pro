#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold city information
struct City {
    char *name;
    int population;
};

int main(int argc, char *argv[]) {
    // Check if the user provided a file name
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1]est;
    FILE *file = fopen(filename, "r");

    // Check if the file could be opened
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the number of cities from the file
    int num_cities;
    fscanf(file, "%d", &num_cities);

    // Allocate memory for the array of structures
    struct City **cities = (struct City **)malloc(num_cities * sizeof(struct City *));
    for (int i = 0; i < num_cities; i++) {
        cities[i] = (struct City *)malloc(sizeof(struct City));
    }

    // Read city information from the file
    for (int i = 0; i < num_cities; i++) {
        char city_name[100];
        int population;

        fscanf(file, "%s %d", city_name, &population);

        cities[i]->name = strdup(city_name);
        cities[i]->population = population;
    }

    // Close the file
    fclose(file);

    // Access and print city information
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s, Population: %d\n", cities[i]->name, cities[i]->population);
    }

    // Free allocated memory
    for (int i = 0; i < num_cities; i++) {
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);

    return 0;
}

