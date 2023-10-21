#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file 'data.txt'");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file) != NULL) {
        int id;
        char name[50];
        double balance;
        if (sscanf(line, "%d %49[^\n] %lf", &id, name, &balance) == 3) {
            printf("ID: %d\n", id);
            printf("Nama: %s\n", name);
            printf("Saldo: %.2lf\n", balance);
            printf("\n");
        } else {
            fprintf(stderr, "%s", line);
        }
    }

    fclose(file);

    return 0;
}
