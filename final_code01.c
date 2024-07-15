#include <stdio.h>
#include <stdlib.h>

struct City {
    char *name;
    int population;
    int area;
};

void replaceCommasWithPeriods(char *str) {
    while (*str) {
        if (*str == ',') {
            *str = '.';
        }
        str++;
    }
}

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

    struct City **cities = NULL;
    int num_cities = 0;

    while (1) {
        char city_name[100];
        int population;
        int area;

        // Attempt to read a city and its population from the file
        int items_read = fscanf(file, "%s %d %d", city_name, &population ,&area);

        if (items_read == 3) {
            // If successful, allocate memory for a new city and add it to the array
            cities = realloc(cities, (num_cities + 1) * sizeof(struct City *));
            cities[num_cities] = (struct City *)malloc(sizeof(struct City));
            cities[num_cities]->name = strdup(city_name);
            cities[num_cities]->population = population;
            cities[num_cities]->area = area;
            num_cities++;
        } else if (items_read == EOF) {
            // If end of file is reached, break out of the loop
            break;
        } else {
            // If an error occurred, print an error message and exit
            printf("Error reading from file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Print city information
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s, Population: %d %d \n", cities[i]->name, cities[i]->population,cities[i]->area);
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);

    return 0;
}

