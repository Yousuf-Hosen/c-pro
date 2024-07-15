
#include <stdio.h>
#include <stdlib.h>

struct City {
    char *name;
    int population;
};

int main(int argc, char *argv[]) {
    char filename[100];

    // Check if the user provided a file name as a command-line parameter
    if (argc == 2) {
        strcpy(filename, argv[1]);
    } else {
        // If not, ask the user for a file name
        printf("Enter the file name: ");
        scanf("%s", filename);
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_cities;
    printf("Enter your number your cities");
    fscanf(file, "%d", &num_cities);

    struct City **cities = (struct City **)malloc(num_cities * sizeof(struct City *));
    for (int i = 0; i < num_cities; i++) {
        cities[i] = (struct City *)malloc(sizeof(struct City));
    }

    for (int i = 0; i < num_cities; i++) {
        char city_name[100];
        int population;

        fscanf(file, "%s %d", city_name, &population);

        cities[i]->name = strdup(city_name);
        cities[i]->population = population;
    }

    fclose(file);

    for (int i = 0; i < num_cities; i++) {
        printf("City: %s, Population: %d\n", cities[i]->name, cities[i]->population);
    }

    for (int i = 0; i < num_cities; i++) {
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);

    return 0;
}
