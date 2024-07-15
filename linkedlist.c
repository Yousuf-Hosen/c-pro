#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct City {
    char *name;
    double area;
    int population;
    struct City *next;
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

    struct City *head = NULL;
    struct City *current = NULL;

    while (!feof(file)) {
        char city_name[100];
        char area_str[100];
        int population;

        // Attempt to read city information from the file
        int items_read = fscanf(file, "%s %s %d\n", city_name, area_str, &population);

        if (items_read == 3) {
            // Replace commas with periods in the area string
            replaceCommasWithPeriods(area_str);

            // Convert the area string to a double
            double area = atof(area_str);

            // Create a new city node
            struct City *new_city = (struct City *)malloc(sizeof(struct City));
            new_city->name = strdup(city_name);
            new_city->area = area;
            new_city->population = population;
            new_city->next = NULL;

            if (head == NULL) {
                head = new_city;
                current = new_city;
            } else {
                current->next = new_city;
                current = new_city;
            }
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
    struct City *current_city = head;
    while (current_city != NULL) {
        printf("City: %s, Area: %lf, Population: %d\n", current_city->name, current_city->area, current_city->population);
        struct City *temp = current_city;
        current_city = current_city->next;
        free(temp->name);
        free(temp);
    }

    return 0;
}
