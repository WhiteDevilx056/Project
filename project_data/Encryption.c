#include <stdio.h>
#include <string.h>

/*
 * Project: File-Guard
 * Logic: ASCII Shifting
 * 
 * Encryption: ch = ch + 100
 * Decryption: ch = ch - 100
 */

void encryptFile(char *location) {
    FILE *source, *target;
    int ch;

    source = fopen(location, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s. Make sure it exists.\n", location);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        ch = ch + 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    remove(location);
    rename("temp.txt", location);

    printf("Congratulations: File encrypted successfully.\n");
}

void decryptFile(char *location) {
    FILE *source, *target;
    int ch;

    source = fopen(location, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s.\n", location);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        ch = ch - 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    remove(location);
    rename("temp.txt", location);

    printf("Congratulations: File decrypted successfully.\n");
}

int main() {
    char filename[100];
    int choice;

    printf("--- File-Guard Project ---\n");
    printf("Enter filename (e.g., data.txt): ");
    scanf("%99s", filename);

    printf("\n1. Encrypt (Lock)\n2. Decrypt (Unlock)\nEnter choice: ");

    /* Choice Validation */
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return 0;
    }

    switch (choice) {
        case 1:
            encryptFile(filename);
            break;

        case 2:
            decryptFile(filename);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
