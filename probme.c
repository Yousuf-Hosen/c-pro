#include <stdio.h>
#include <stdlib.h>

struct City {
    char *name;
    float latitude;
    float longitude;
    int population;
    char *district;
    char *division;
};

void free_memory(struct City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        free(cities[i].name);
        free(cities[i].district);
        free(cities[i].division);
    }
    free(cities);
}

int main() {
    FILE *file;
    char line[1000]; // Assuming a maximum line length of 1000 characters

    file = fopen("test.txt", "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int num_cities;
    fscanf(file, "%d", &num_cities);

    struct City *cities = (struct City *)malloc(num_cities * sizeof(struct City));
    if (!cities) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < num_cities; i++) {
        cities[i].name = (char *)malloc(100 * sizeof(char)); // Assuming max city name length of 100 characters
        cities[i].district = (char *)malloc(100 * sizeof(char)); // Assuming max district name length of 100 characters
        cities[i].division = (char *)malloc(100 * sizeof(char)); // Assuming max division name length of 100 characters

        if (!cities[i].name || !cities[i].district || !cities[i].division) {
            perror("Error allocating memory");
            free_memory(cities, i);
            fclose(file);
            return 1;
        }

        fscanf(file, "%s %f %f %d %s %s",
               cities[i].name, &cities[i].latitude, &cities[i].longitude,
               &cities[i].population, cities[i].district, cities[i].division);
    }

    fclose(file);

    // Use the array of structures here
    // For example, print the data
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s, Latitude: %f, Longitude: %f, Population: %d, District: %s, Division: %s\n",
               cities[i].name, cities[i].latitude, cities[i].longitude,
               cities[i].population, cities[i].district, cities[i].division);
    }

    // Don't forget to free the allocated memory
    free_memory(cities, num_cities);

    return 0;
}

