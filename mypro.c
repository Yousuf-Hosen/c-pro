#include <stdio.h>

struct City {
    char *name;
    int population;
};

void free_memory(struct City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        free(cities[i].name);
    }
    free(cities);
}

int main() {
    FILE *file;
    char filename[100]; // Assuming a maximum filename length of 100 characters
    char content[1000]; // Assuming a maximum content length of 1000 characters

    // Prompt user for the file name
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file was successfully opened
    if (file == NULL) {
        printf("Could not open the file %s\n", filename);
        return 1; // Return an error code
    }

    // Read and print the contents of the file
    while (fscanf(file, "%s", content) != EOF) {
        printf("%s ", content);
    }


    // Close the file
    fclose(file);

    return 0;
}

