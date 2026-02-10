#include <stdio.h>
#include <stdlib.h>

/*
 * Project: File-Guard
 * Logic: ASCII Shifting (The Secret Sauce)
 * 
 * Encryption: ch = ch + 100
 * Decryption: ch = ch - 100
 */

void encryptFile(char *fileToEncrypt) {
    FILE *source, *target;
    int ch;

    source = fopen(fileToEncrypt, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s. Make sure it exists.\n", fileToEncrypt);
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
    remove(fileToEncrypt);
    rename("temp.txt", fileToEncrypt);

    printf("Magic Done: File encrypted successfully (Gibberish mode ON).\n");
}

void decryptFile(char *fileToDecrypt) {
    FILE *source, *target;
    int ch;

    source = fopen(fileToDecrypt, "r");
    if (source == NULL) {
        printf("Error: Could not open file %s.\n", fileToDecrypt);
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
    remove(fileToDecrypt);
    rename("temp.txt", fileToDecrypt);

    printf("Magic Done: File decrypted successfully (Original content restored).\n");
}

int main() {
    char userFilename[100];
    int choice;

    printf("--- File-Guard Project ---\n");
    printf("Enter filename (e.g., data.txt): ");
    scanf("%s", userFilename);

    printf("\n1. Encrypt (Lock)\n2. Decrypt (Unlock)\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encryptFile(userFilename);
            break;
        case 2:
            decryptFile(userFilename);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
