#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City {
    char *name;
    double area;
    int population;
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
    int max_cities = 10; // Initial allocation for 10 cities

    while (!feof(file)) {
        char city_name[100];
        char area_str[100];
        int population;

        // Attempt to read city information from the file
        int items_read = fscanf(file, "%s %s %d\n", city_name, area_str, &population);

        if (items_read == 3) {
                replaceCommasWithPeriods(area_str);
            double area = atof(area_str);

            if (num_cities == max_cities - 1) {
                // If the array is full, reallocate more space
                max_cities *= 2;
                cities = realloc(cities, max_cities * sizeof(struct City *));
            }

            // Allocate memory for a new city and add it to the array
            cities[num_cities] = (struct City *)malloc(sizeof(struct City));
            cities[num_cities]->name = strdup(city_name);
            cities[num_cities]->area = area;
            cities[num_cities]->population = population;
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
        printf("City: %s, Area: %lf, Population: %d\n", cities[i]->name, cities[i]->area, cities[i]->population);
        free(cities[i]->name);
        free(cities[i]);
    }
    free(cities);

    return 0;
}
