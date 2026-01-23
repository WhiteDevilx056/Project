#include <stdio.h>
#include <stdlib.h>

/*
 * Project: File-Guard
 * Logic: ASCII Shifting (The Secret Sauce)
 * 
 * Encryption: ch = ch + 100
 * Decryption: ch = ch - 100
 */

void encryptFile(char *filename) {
    FILE *source, *target;
    int ch;

    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s. Make sure it exists.\n", filename);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    // Logic: ch = ch + 100
    while ((ch = fgetc(source)) != EOF) {
        ch = ch + 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    // Replace original file with encrypted file
    remove(filename);
    rename("temp.txt", filename);

    printf("Magic Done: File encrypted successfully (Gibberish mode ON).\n");
}

void decryptFile(char *filename) {
    FILE *source, *target;
    int ch;

    source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    target = fopen("temp.txt", "w");
    if (target == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(source);
        return;
    }

    // Logic: ch = ch - 100
    while ((ch = fgetc(source)) != EOF) {
        ch = ch - 100;
        fputc(ch, target);
    }

    fclose(source);
    fclose(target);

    // Replace original file with decrypted file
    remove(filename);
    rename("temp.txt", filename);

    printf("Magic Done: File decrypted successfully (Original content restored).\n");
}

int main() {
    char filename[100];
    int choice;

    printf("--- File-Guard Project ---\n");
    printf("Enter filename (e.g., data.txt): ");
    scanf("%s", filename);

    printf("\n1. Encrypt (Lock)\n2. Decrypt (Unlock)\nEnter choice: ");
    scanf("%d", &choice);

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
