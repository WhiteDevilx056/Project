#include <stdio.h>
#include <string.h>

/*
-------------------------------------------------
 Program Name : File Guard System
 Purpose      : Encrypt and Decrypt Text Files
 Developer    : (Your Name)
-------------------------------------------------
*/

/* Function to Encrypt File */
void encryptFile(char *location)
{
    FILE *source, *target;   // File pointers
    int ch;                  // Variable to store each character

    /* Open original file in read mode */
    source = fopen(location, "r");

    if (source == NULL)
    {
        printf("\n[ERROR] File could not be opened!\n");
        return;
    }

    /* Create temporary file in write mode */
    target = fopen("temp.txt", "w");

    if (target == NULL)
    {
        printf("\n[ERROR] Temporary file could not be created!\n");
        fclose(source);
        return;
    }

    /* Encryption Logic: Add 100 to each character */
    while ((ch = fgetc(source)) != EOF)
    {
        ch = ch + 100;          // Encrypt character
        fputc(ch, target);     // Write encrypted character
    }

    /* Close both files */
    fclose(source);
    fclose(target);

    /* Replace original file with encrypted file */
    remove(location);
    rename("temp.txt", location);

    printf("\n[SUCCESS] File encrypted successfully!\n");
}

/* Function to Decrypt File */
void decryptFile(char *location)
{
    FILE *source, *target;   // File pointers
    int ch;                  // Variable to store each character

    /* Open encrypted file in read mode */
    source = fopen(location, "r");

    if (source == NULL)
    {
        printf("\n[ERROR] File could not be opened!\n");
        return;
    }

    /* Create temporary file */
    target = fopen("temp.txt", "w");

    if (target == NULL)
    {
        printf("\n[ERROR] Temporary file could not be created!\n");
        fclose(source);
        return;
    }

    /* Decryption Logic: Subtract 100 from each character */
    while ((ch = fgetc(source)) != EOF)
    {
        ch = ch - 100;          // Decrypt character
        fputc(ch, target);     // Write original character
    }

    /* Close files */
    fclose(source);
    fclose(target);

    /* Replace encrypted file with decrypted file */
    remove(location);
    rename("temp.txt", location);

    printf("\n[SUCCESS] File decrypted successfully!\n");
}

/* Main Function */
int main()
{
    char filename[100];   // Store file name
    int choice;           // Store user choice

    /* Program Banner */
    printf("\n====================================\n");
    printf("        FILE GUARD SYSTEM\n");
    printf("     Encrypt & Decrypt Files\n");
    printf("====================================\n");

    /* Take file name from user */
    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    /* Display Menu */
    printf("\n--------- MENU ---------\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("------------------------\n");

    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    /* Perform selected operation */
    if (choice == 1)
    {
        encryptFile(filename);
    }
    else if (choice == 2)
    {
        decryptFile(filename);
    }
    else
    {
        printf("\n[ERROR] Invalid Choice!\n");
    }

    printf("\nThank You for Using File Guard System.\n");

    return 0;
}
