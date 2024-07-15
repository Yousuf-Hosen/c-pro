#include <stdio.h>

int main() {
    FILE *file;
    char line[1000]; // Assuming a maximum line length of 1000 characters

    file = fopen("Bangladesh.txt", "r"); // Replace "example.txt" with your file name

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

