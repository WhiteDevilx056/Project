#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Project: File-Guard (Secure Version)
 * Logic: ASCII Shifting with Password Protection
 * 
 * Features:
 * 1. Encrypt/Decrypt using fgetc/fputc
 * 2. Switch Case for menu
 * 3. Password Protection
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

    printf("\n*************************************************\n");
    printf("*   Magic Done: File encrypted successfully!    *\n");
    printf("*************************************************\n");
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

    remove(filename);
    rename("temp.txt", filename);

    printf("\n*************************************************\n");
    printf("*   Magic Done: File decrypted successfully!    *\n");
    printf("*************************************************\n");
}

int main() {
    char filename[100];
    int choice;
    char password[20];
    const char secretPass[] = "1234"; // Yahan apna password set karein
    FILE *checkFile;

    printf("\n*************************************************\n");
    printf("*         File-Guard Project (Secure)           *\n");
    printf("*************************************************\n");
    printf("Enter filename (e.g., data.txt): ");
    scanf("%s", filename);

    // Step 1: Check if file exists immediately
    checkFile = fopen(filename, "r");
    if (checkFile == NULL) {
        printf("File not found!\n");
        return 0;
    }
    fclose(checkFile);

    // Step 2: Menu Loop (Validates input)
    while (1) {
        printf("\n-------------------------------------------------\n");
        printf("1. Encrypt (Lock)\n2. Decrypt (Unlock)\n3. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            return 0; // Exit program
        } else if (choice == 1 || choice == 2) {
            break; // Valid choice, proceed
        } else {
            printf("Wrong input only choose option bw 1 to 3.\n");
        }
    }

    int attempts = 0;
    while (attempts < 3) {
        printf("\n[SECURE ACCESS] Enter Password to continue: ");
        scanf("%s", password);

        if (strcmp(password, secretPass) == 0) {
            break;
        }
        printf("Please enter correct pass.\n");
        attempts++;
    }

    if (attempts == 3) {
        printf("Try again later\n");
        return 0;
    }

    switch (choice) {
        case 1:
            encryptFile(filename);
            break;
        case 2:
            decryptFile(filename);
            break;
    }

    return 0;
}